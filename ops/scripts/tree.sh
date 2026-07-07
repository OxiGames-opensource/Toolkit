#!/usr/bin/env bash

set -euo pipefail

CURRENT_DIR="$(pwd)"

find_project_root() {
    local dir="$CURRENT_DIR"

    while [[ "$dir" != "/" ]]; do
        if [[ "$(basename "$dir")" == "app" ]]; then
            dirname "$dir"
            return 0
        fi

        if [[ -d "$dir/app" ]]; then
            echo "$dir"
            return 0
        fi

        dir="$(dirname "$dir")"
    done

    echo "[ERROR] Cannot find project root above app directory" >&2
    return 1
}

PROJECT_ROOT="$(find_project_root)"
TARGET="${1:-$PROJECT_ROOT}"
DEPTH="${DEPTH:-6}"

echo "[INFO] Project:         $PROJECT_ROOT"
echo "[INFO] Target:          $TARGET"
echo "[INFO] Depth:           $DEPTH"
echo

cd "$TARGET"

tree -a -L "$DEPTH" \
    -I ".git|node_modules|vendor"

# tree -a -L "$DEPTH" \
#     -I ".git|node_modules|vendor|var/log|var/cache|result"