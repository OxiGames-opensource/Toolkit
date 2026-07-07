# Example Plugin

Example OxiFabrics Ops plugin.

This plugin demonstrates the minimum structure required for an Ops plugin.

## Structure

```text
example-plugin/
├── config.json
├── index.sh
├── icon.png
└── README.md
```

## Required Files

### config.json

Plugin metadata used by OxiFabrics.

### index.sh

Plugin entry point.

### icon.png

Plugin icon displayed in Ops Center.

### README.md

Plugin documentation.

## Required Actions

### iconAction

Returns plugin label for the Ops Center button.

### init

Default plugin action executed when the plugin is opened.

## Purpose

Use this plugin as a starting point for creating custom Ops plugins.

Copy the plugin, rename it, and replace the example logic with your own implementation.
