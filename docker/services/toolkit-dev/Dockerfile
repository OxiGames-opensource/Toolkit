FROM ubuntu:24.04

ARG APP_UID=1000
ARG APP_GID=1000
ARG APP_USER=app

# Add user
COPY helper/setup-user.sh /usr/local/bin/setup-user.sh

RUN chmod +x /usr/local/bin/setup-user.sh \
    && /usr/local/bin/setup-user.sh

# Add console styles
COPY helper/shell-comfort.sh /usr/local/bin/shell-comfort.sh

RUN chmod +x /usr/local/bin/shell-comfort.sh \
    && /usr/local/bin/shell-comfort.sh


RUN apt-get update && apt-get install -y \
    build-essential \
    cmake \
    ninja-build\
    gdb \
    pkg-config \
    git \
    curl \
    ca-certificates \
    python3 \
    python3-pip \
    && apt-get clean \
    && rm -rf /var/lib/apt/lists/* /tmp/* /var/tmp/*
