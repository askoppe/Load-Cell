This devcontainer provides a minimal Docker-based development container with the PlatformIO CLI installed.

How to use
- Open this project in VS Code and choose "Reopen in Container" from the Command Palette.
- After the container builds, verify PlatformIO is available:

```
pio --version
```

Notes
- The Docker image installs `platformio` via `pip3`.
- If you need additional toolchains (AVR, ARM), install them inside the container or extend the Dockerfile.
