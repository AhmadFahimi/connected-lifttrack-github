# Connected LiftTrack

A Qt Widgets interface prototype for an embedded Linux lift-truck dispatch panel.

## Status and scope

| Area | Status |
|---|---|
| Target | Raspberry Pi 4, ARM64 |
| Embedded Linux configuration | Buildroot 2024.02.13, commit `e687e381` |
| Qt | 6.4 series in the recorded Buildroot configuration; patch version not confirmed |
| Display backend | `linuxfb` selected in the Buildroot configuration |
| Application | Standalone Qt Widgets UI prototype; source is not integrated as a Buildroot package |
| Dashboard values | Hard-coded illustrative sample data; no live telemetry connection |
| MQTT / SQLite | Packages are enabled in the image configuration; this application does not connect to them |
| Emergency button | Demo-only UI response; sends no command and stops no vehicle |
| Touch interaction | Counts a UI button click; it is not a multi-touch hardware test |
| Automatic startup | Not included or verified |

## Repository contents

- `app/LiftTrackTest/` — Qt/CMake application source and UI form.
- `configs/lifttrack_rpi4_defconfig` — reduced Buildroot defconfig exported from the active configuration.
- `docs/build-provenance.txt` — recorded Buildroot version and configuration notes.

The eight fleet rows use generic demo identifiers and zones. No customer telemetry, production endpoints, credentials, generated Buildroot output, disk images, or deployed binaries are included.

## Build the base Buildroot image

Use the Buildroot source at the revision recorded in `docs/build-provenance.txt`. From the Buildroot source directory:

```sh
make BR2_DEFCONFIG=/path/to/connected-lifttrack-github/configs/lifttrack_rpi4_defconfig defconfig
make
```

This builds the configured base image. It does **not** build or install `LiftTrackTest`; the application is not currently wired into Buildroot through a package, external tree, or root filesystem overlay.

## Build the Qt application separately

With a Qt development installation available to CMake, build the standalone application on the host:

```sh
cmake -S app/LiftTrackTest -B build -DCMAKE_PREFIX_PATH=/path/to/Qt
cmake --build build
```

For deployment on the Raspberry Pi, the application must be cross-compiled with a Qt toolchain matching the target image. Cross-compilation and image integration are not automated by this repository.

## Safety and security

This repository is a UI prototype, not a vehicle-control system. Do not connect the demo emergency button to real equipment without a separately designed, safety-reviewed control path. Replace sample values with synthetic data before screenshots or demonstrations, and never commit customer data, credentials, or production connection details.
