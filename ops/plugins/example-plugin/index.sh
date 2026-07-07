#!/usr/bin/env bash
set -Eeuo pipefail

iconAction() {
  echo "⚙️ Example Plugin"
}

init() {
  echo "[INFO] Use this plugin as a template for custom Ops tools"
  echo "[WARN] This is a demo warning message"
  echo "[ERR] This is a demo error message"
  echo "[OK] Plugin structure is valid"
  openIdeTab
  openIdeTabFile
}

openIdeTab() {
  echo "[OPEN_VIEW] Example Plugin|<h2>Example Plugin Inline</h2><p>IDE tab opened from Ops plugin.</p>"
}

openIdeTabFile() {
  local plugin_dir
  plugin_dir="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"

  echo "[OPEN_VIEW_FILE] Example Plugin|$plugin_dir/src/views/index.html"
}

ACTION="${1:-init}"

case "$ACTION" in
  iconAction)
    iconAction
    ;;
  init)
    init
    ;;
  openIdeTab)
    openIdeTab
    ;;
  *)
    echo "[ERR] Unknown action: $ACTION" >&2
    exit 1
    ;;
esac