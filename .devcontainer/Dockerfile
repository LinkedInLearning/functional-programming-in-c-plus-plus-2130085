FROM gcc:13

# Install dependencies
RUN apt-get update && \
    apt-get install -y --no-install-recommends \
    cmake \
    ninja-build \
    clang \
    clangd \
    clang-tidy \
    gdb \
    pkg-config \
    libboost-all-dev && \
    apt-get clean && rm -rf /var/lib/apt/lists/*

# Set default shell
ENV SHELL /bin/bash