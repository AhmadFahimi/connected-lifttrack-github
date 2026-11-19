# Connected Lifttrack

A Qt interface prototype for an embedded Linux lift-truck dispatch panel.

## Project status

| Area | Status |
|---|---|
| Target | Raspberry Pi 4, ARM64 |
| Embedded Linux | Buildroot 2024.02.13, commit e687e381 |
| Qt | 6.4 series; exact patch version not yet confirmed |
| Display | Qt linuxfb selected in the active Buildroot configuration |
| Application | Qt Widgets source included |
| MQTT and SQLite | Packages enabled in the image configuration; application integration is not claimed |
| Automatic startup | Not included or verified |

## Contents

- `app/LiftTrackTest/` — Qt/CMake application source.
- `configs/lifttrack_rpi4_defconfig` — reduced defconfig exported from the active configuration.
- `docs/build-provenance.txt` — build version and configuration notes.

Generated output, Buildroot source, disk images, target binaries, credentials, customer data and production endpoints are not included.

## Configure and build

From a Buildroot source tree at the recorded revision, load this defconfig and build:


```sh
make BR2_DEFCONFIG=/path/to/connected-lifttrack-github/configs/lifttrack_rpi4_defconfig defconfig
make

```

Build and deployment of the Qt application require a toolchain matching the target image.
