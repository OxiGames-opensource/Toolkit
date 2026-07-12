# Module Architecture

## Module Philosophy

Every top-level module is an independent subsystem.

Each module:

- owns its internal implementation;
- exposes a single public coordinator;
- communicates with other modules only through its public interface or the Event Bus;
- owns a single high-level responsibility.

Modules are designed to be isolated and independently testable.

---

## Module Execution Flow

Every executable module follows the same lifecycle.

```text
Launcher
        │
        ▼
Bootstrap
        │
        ▼
Kernel
```

### Launcher

The Launcher is the only component that receives control from the operating system or an external process.

Responsibilities:

- application entry point;
- parse command-line arguments;
- select execution mode;
- transfer control to Bootstrap.

The Launcher contains no business logic.

---

### Bootstrap

Bootstrap prepares the execution environment.

Responsibilities:

- initialize configuration;
- initialize startup diagnostics;
- verify environment;
- create core components;
- transfer control to Kernel.

Bootstrap performs one-time initialization only.

---

### Kernel

The Kernel is the public coordinator of a module.

Responsibilities:

- manage module lifecycle;
- coordinate internal components;
- expose the public module interface.

Business logic belongs to internal module components.

---

## Module Structure

Every module follows the same architectural principles.

```text
Module/
├── Contract/
├── Kernel/
└── ...
```

Additional directories are introduced only when required by the module.

Example:

```text
Runtime/
├── Context/
├── Contract/
├── Event/
├── EventBus/
├── Hook/
├── Kernel/
├── Lifecycle/
├── Loader/
└── Process/

Platform/
├── Contract/
├── Kernel/
├── Linux/
├── MacOS/
└── Windows/

Plugin/
├── Contract/
├── Kernel/
├── Loader/
├── Manager/
└── Registry/

Diagnostics/
├── Contract/
├── Kernel/
├── Logger/
├── Reporter/
└── StackTrace/

Tools/
├── Builder/
├── Ghidra/
└── Kernel/
```

The internal structure reflects module responsibilities rather than enforcing strict symmetry.

---

## Module Isolation

Modules own their internal implementation.

External modules must never:

- instantiate internal components;
- access internal services;
- depend on internal directory layout;
- bypass the module Kernel.

---

## Module Communication

Modules communicate only through:

- public Kernel interfaces;
- Event Bus.

Direct communication with internal module components is forbidden.

Allowed:

```text
Plugin --------> Runtime::Kernel
Diagnostics ---> Runtime::Kernel
Tools ---------> Runtime::Kernel

Runtime -------> EventBus

Runtime -------> Plugin::Kernel
Runtime -------> Diagnostics::Kernel
Runtime -------> Tools::Kernel
```

Forbidden:

```text
Plugin -------> Runtime/Hook
Plugin -------> Runtime/Process
Logger -------> Runtime/Loader
Tools --------> Diagnostics/Logger
Diagnostics --> Plugin/Manager
```

---

# Event Bus Architecture

## Purpose

OxiToolkit uses an event-driven architecture for communication between independent modules.

The Event Bus is the only asynchronous communication mechanism between modules.

---

## Core Principles

- Events are immutable.
- Events describe facts that already happened.
- Events contain no business logic.
- Events never modify runtime state.
- Events expose no mutating operations.
- Every event type has a single owner.
- Modules never bypass the Event Bus.
- Listeners never communicate directly.

---

## Event Naming

Events describe facts, never commands.

Correct:

```text
ProcessStarted
ProcessExited
ModuleLoaded
HookAttached
DirectDrawCreated
DisplayModeChanged
PluginLoaded
LogWritten
```

Incorrect:

```text
StartProcess
RunLogger
ExecuteHook
DoSomething
AttachHookNow
```

---

## Event Ownership

Only the owning module may publish an event.

Examples:

```text
Runtime/Process     -> ProcessStarted
Runtime/Hook        -> HookAttached
Plugin/Manager      -> PluginLoaded
Diagnostics/Logger  -> LogWritten
```

Listeners must never publish events owned by another module.

---

## Event Immutability

Events are fully initialized during construction.

Correct:

```text
ProcessStarted(
    pid,
    executablePath,
    commandLine,
    timestamp
)
```

Forbidden:

```text
modify(event)
update(event)
mutate(event)
```

---

## Listener Rules

A listener may:

- read event data;
- perform local work;
- publish new events only if it owns them.

A listener must never:

- modify an event;
- invoke another listener;
- call another module directly;
- publish foreign events.

---

## Event Categories

### Runtime Events

```text
ProcessStarted
ProcessExited
ModuleLoaded
HookAttached
ApiCalled
```

### Toolkit Events

```text
PluginLoaded
ListenerRegistered
ConfigurationLoaded
BuildStarted
BuildCompleted
```

### Diagnostic Events

```text
LogWritten
ReportGenerated
StackTraceCaptured
```