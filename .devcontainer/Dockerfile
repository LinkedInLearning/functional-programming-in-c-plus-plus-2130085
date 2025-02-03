FROM mcr.microsoft.com/devcontainers/cpp:debian-12

# Install additional packages
RUN apt-get update && export DEBIAN_FRONTEND=noninteractive \
    && apt-get -y install --no-install-recommends \
    build-essential \
    cmake \
    clang \
    clangd \
    clang-format \
    clang-tidy \
    gdb \
    ninja-build \
    pkg-config \
    git \
    && apt-get clean -y \
    && rm -rf /var/lib/apt/lists/*

# Set the default shell to bash.
ENV SHELL /bin/bash
