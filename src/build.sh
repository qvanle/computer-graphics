#!/bin/bash

# Colors
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[0;33m'
NC='\033[0m' # No Color

# Step 1: Run CMake
echo -e "${YELLOW}⚙️  Running CMake...${NC}"
cmake -S . -B build || { echo -e "${RED}❌ CMake failed! Exiting.${NC}"; exit 1; }

# Step 2: Build the project
echo -e "${YELLOW}🔨 Building project...${NC}"
cmake --build build || { echo -e "${RED}❌ Build failed! Exiting.${NC}"; exit 1; }

# Step 3: Run the specified executable
EXECUTABLE="window"
if [[ -z "$EXECUTABLE" ]]; then
    echo -e "${RED}⚠️  No executable specified! Use ./build.sh <executable_name>${NC}"
    exit 1
fi

if [[ ! -f "build/$EXECUTABLE" ]]; then
    echo -e "${RED}🚫 Executable 'build/$EXECUTABLE' not found!${NC}"
    exit 1
fi

echo -e "${GREEN}🚀 Running $EXECUTABLE...${NC}"
./build/$EXECUTABLE
