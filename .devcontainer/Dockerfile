FROM mcr.microsoft.com/vscode/devcontainers/base:ubuntu

ENV DEBIAN_FRONTEND=noninteractive

RUN apt-get update \
    && apt-get install -y --no-install-recommends \
        python3 \
        python3-venv \
        python3-pip \
        git \
        build-essential \
        libusb-1.0-0-dev \
        udev \
        ca-certificates \
    && python3 -m venv /opt/venv \
    && /opt/venv/bin/pip install --upgrade pip setuptools wheel \
    && /opt/venv/bin/pip install platformio \
    && ln -s /opt/venv/bin/pio /usr/local/bin/pio \
    && apt-get clean \
    && rm -rf /var/lib/apt/lists/*

USER vscode
