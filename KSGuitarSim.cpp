// Copyright 2020 Adam Tremblay

#include <math.h>
#include <cstring>
#include <iostream>
#include <vector>
#include <SFML/Audio.hpp>
#include "StringSound.hpp"

const int A = 440;
const int SPS = 44100;
const char NOTES[] = "q2we4r5ty7u8i9op-[=zxdcfvgbnjmk,.;/' ";
const int NOTES_SIZE = std::strlen(NOTES);

int getNoteIndex(char a);

void makeSamples(std::vector<std::vector<sf::Int16> >* samples);

void makeSoundBuffers(
    std::vector<sf::SoundBuffer>* sound_buffers,
    const std::vector<std::vector<sf::Int16> >& samples);

void makeSounds(
    std::vector<sf::Sound>* sounds,
    const std::vector<sf::SoundBuffer>& sound_buffers);

int main() {
    std::vector<std::vector<sf::Int16> > audio_sample_stream;
    std::vector<sf::SoundBuffer> sound_buffers;
    std::vector<sf::Sound> sounds;

    makeSamples(&audio_sample_stream);
    makeSoundBuffers(&sound_buffers, audio_sample_stream);
    makeSounds(&sounds, sound_buffers);

    sf::RenderWindow window(sf::VideoMode(300, 200), "Guitar Hero");
    sf::Event event;

    while (window.isOpen()) {
        while (window.pollEvent(event)) {
            int index;
            switch (event.type) {
                case sf::Event::Closed:
                    window.close();
                    break;

                case sf::Event::TextEntered:
                    index = NOTES_SIZE - 1 - getNoteIndex(event.text.unicode);
                    if (index >= 0 && index < NOTES_SIZE) {
                        sounds.at(index).play();
                    }
                    break;

                default:
                    break;
            }

            window.clear();
            window.display();
        }
    }

    return 0;
}

int getNoteIndex(char a) {
    int index = -1;
    for (int i = 0; i < NOTES_SIZE; i++) {
        if (a == NOTES[i]) {
            index = i;
        }
    }

    return index;
}

void makeSamples(std::vector<std::vector<sf::Int16> >* samples) {
    for (int i = 0; i < NOTES_SIZE; i++) {
        StringSound ss(A * pow(2, (i - 24) / 12.0));
        ss.pluck();
        int duration = 8;
        std::vector<sf::Int16> sample;
        for (int i= 0; i < SPS * duration; i++) {
            ss.tic();
            sample.push_back(ss.sample());
        }
        samples->push_back(sample);
    }
}

void makeSoundBuffers(std::vector<sf::SoundBuffer>* sound_buffers,
    const std::vector<std::vector<sf::Int16> >& samples) {
    for (int i = 0; i < NOTES_SIZE; i++) {
        sf::SoundBuffer sound_buf;
        int s_size = samples.at(i).size();
        sound_buf.loadFromSamples(&samples.at(i).at(0), s_size, 2, SPS);
        sound_buffers->push_back(sound_buf);
    }
}

void makeSounds(std::vector<sf::Sound>* sounds,
    const std::vector<sf::SoundBuffer>& sound_buffers) {
    for (int i = 0; i < NOTES_SIZE; i++) {
        sf::Sound sound;
        sound.setBuffer(sound_buffers.at(i));
        sounds->push_back(sound);
    }
}

