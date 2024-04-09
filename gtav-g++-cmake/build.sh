#!/bin/bash

cmake -Bbuild -GNinja .
cmake --build build --clean-first

