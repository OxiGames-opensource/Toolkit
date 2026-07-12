# Development Workflow

## Purpose

This document defines the development workflow used by OxiToolkit.

Its goal is to ensure that every feature is developed, tested and released using a reproducible, platform-independent process.

---

# Core Principles

- Architecture decisions are recorded before implementation.
- Development is task-driven.
- Every change belongs to an Issue.
- Issues belong to Milestones.
- Runtime is never executed directly from the source repository.
- Development and Release packages share the same runtime layout.
- Documentation is updated only after implementation has been verified.

---

# Development Lifecycle

```text
Project Vision
        │
        ▼
Architecture Decision
(dev-notes)
        │
        ▼
Milestone
        │
        ▼
Issue
        │
        ▼
Development
        │
        ▼
Update dev-notes
        │
        ▼
Build Development Package
        │
        ▼
Run & Test
        │
        ▼
Collect Logs
        │
        ▼
Fix
        │
        ▼
Commit
        │
        ▼
Push
        │
        ▼
Close Issue
        │
        ▼
Update Wiki
        │
        ▼
Milestone Complete
        │
        ▼
Release
```

---

# Development Process

Every feature follows the same workflow.

1. Create or select an Issue.
2. Create a feature branch.
3. Implement the feature.
4. Update development documentation if architectural decisions were made.
5. Build a Development Package.
6. Test using the Development Package.
7. Collect logs.
8. Fix discovered problems.
9. Commit changes.
10. Push branch.
11. Close the Issue.
12. Update the Wiki after verification.

---

# Package-First Development

## Principle

OxiToolkit follows the **Package-First Development** model.

The Runtime is **never executed directly from the source repository**.

Every runtime test is performed using a generated Development Package.

---

## Workflow

```text
Source Repository
        │
        ▼
Build
        │
        ▼
Development Package
        │
        ▼
Isolated Test Directory
        │
        ▼
Game Launch
        │
        ▼
Logs
        │
        ▼
Analysis
        │
        ▼
Fix
        │
        ▼
Build Again
```

---

## Development Package

Purpose:

- isolated runtime environment;
- runtime debugging;
- diagnostics;
- reproducible testing.

Typical layout:

```text
bin/
config/
plugins/
var/
└── log/
README.md
run.bat
run.sh
```

Development Packages are generated into:

```text
app/dist/linux/
app/dist/windows/
app/dist/proton/
app/dist/source/
```

---

## Release Package

Release Packages are created from the same packaging model.

Differences:

- optimized binaries;
- release configuration;
- reduced logging;
- debug functionality disabled.

The runtime layout remains identical.

---

# Documentation Workflow

During active development all engineering decisions are stored in **dev-notes**.

The GitHub Wiki contains only verified documentation.

Workflow:

```text
Discussion
        │
        ▼
Decision
        │
        ▼
dev-notes
        │
        ▼
Implementation
        │
        ▼
Verification
        │
        ▼
Wiki
```

---

# Git Workflow

Each Issue is developed inside its own feature branch.

Example:

```text
main
        │
        └── feature/2-runtime-bootstrap
```

More complex features may contain child branches.

Example:

```text
feature/3-event-bus
feature/3/18-event-interface
feature/3/19-listener-registry
feature/3/20-dispatcher
```

---

# Milestones

Milestones define major project goals.

A Milestone contains multiple Issues.

Workflow:

```text
Milestone
        │
        ├── Issue
        ├── Issue
        ├── Issue
        └── Issue
```

A Milestone is completed only after every Issue has been completed.

---

# Development Rules

## Runtime

- Never execute Runtime directly from the repository.
- Always execute Runtime from a generated Development Package.

## Testing

- Test using generated packages only.
- Every package must be isolated.
- Runtime logs are stored inside the package.

## Documentation

- Record architectural decisions immediately.
- Update Wiki only after implementation has been verified.

## Git

- One Issue → one feature branch.
- Small focused commits.
- Push frequently.

---

# Benefits

This workflow provides:

- reproducible development;
- reproducible testing;
- platform-independent workflow;
- identical developer and user runtime layout;
- isolated execution environment;
- easier debugging;
- predictable releases;
- maintainable documentation.

---

# Summary

The complete development flow is:

```text
Architecture
        │
        ▼
Issue
        │
        ▼
Development
        │
        ▼
Development Package
        │
        ▼
Testing
        │
        ▼
Logs
        │
        ▼
Fix
        │
        ▼
Commit
        │
        ▼
Push
        │
        ▼
Close Issue
        │
        ▼
Wiki
        │
        ▼
Release
```