FROM tobix/pywine:3.12

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

# Default command for interactive usage.
# CMD ["sh"]

# ---------------------------------------------------------------------
# Optional shell comfort tools
# Uncomment if this container is used interactively.
# RUN apt-get update && apt-get install -y \
#     bash \
#     less \
#     nano \
#     tree \
#     curl \
#     vim \
#     mc \
#     htop \
#     git \
#     wget \
#     && apt-get clean \
#     && rm -rf /var/lib/apt/lists/* /tmp/* /var/tmp/*
# ---------------------------------------------------------------------

# ---------------------------------------------------------------------
# Package install pattern
#
# Keep apt cleanup in the same RUN layer where apt-get update/install is used.
# Do not move cleanup to a separate final RUN, otherwise previous layers
# will still keep package indexes/cache.
#
# RUN apt-get update \
#     && apt-get install -y --no-install-recommends \
#         package1 \
#         package2 \
#     && apt-get clean \
#     && rm -rf /var/lib/apt/lists/* /tmp/* /var/tmp/*
# ---------------------------------------------------------------------