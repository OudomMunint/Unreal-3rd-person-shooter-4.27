# 3rd Person Shooter (still thinking of a name)

## Maintenance: ![maintenance-status](https://img.shields.io/badge/maintenance-passively--maintained-yellowgreen.svg)

## Release Pipeline: [![UE Release](https://github.com/OudomMunint/Unreal-3rd-person-shooter-4.27/actions/workflows/release.yml/badge.svg)](https://github.com/OudomMunint/Unreal-3rd-person-shooter-4.27/actions/workflows/release.yml)

# Recommened Specs
| Specification     | Minimum                          | Recommended                     |
|-------------------|----------------------------------|---------------------------------|
| CPU               | i7-3770K or Ryzen 3200G          | i7-8750H or Ryzen 5 4600H       |
| RAM               | 8GB                              | 16GB or higher                  |
| Storage           | Nvme SSD5GB of free space        | Nvme SSD5GB of free space       |
| GPU               | Intel Iris Xe 96EU               | GTX 1050 or RX 550              |
| OS                | Windows 10 or macOS 10.12        | Windows 10 or macOS 10.15       |

‼️ Apple silicon isn't supported `M1` & `M2` SKUs <br>
‼️ For now `FSR 2` Doesn't work on macOS 13+ use `r.FidelityFX.FSR2.Enabled 0` to disable FSR<br>
‼️ DLSS only supprts `RTX 20 Series` and newer. <br>
‼️ Use `r.FidelityFX.FSR2.EnableFP16OnNvDX11` to enable half precision mode if GPU < `Maxwell` / `GCN 1.0` <br>
‼️ `UE 5.2.1` will not launch because of `FSR 2.2.1` <br>

# FSR commands
| Commands                                | Actions                          |
|-----------------------------------------|----------------------------------|
| `r.FidelityFX.FSR2.Enabled 0`           | Turn FSR 2 `Off`                 |
| `r.FidelityFX.FSR2.Enabled 1`           | Turn FSR 2 `On`                  |
| `r.FidelityFX.FSR2.RCAS.Enabled`        | Contrast adaptive sharpening     |
| `r.FidelityFX.FSR2.QualityMode 1`       | FSR 2 Quality Mode               |
| `r.FidelityFX.FSR2.QualityMode 2`       | FSR 2 Balanced Mode              |
| `r.FidelityFX.FSR2.QualityMode 3`       | FSR 2 Performance Mode           |
| `r.FidelityFX.FSR2.QualityMode 4`       | FSR 2 Ultra Performance Mode     |

# Optimization
#### These Settings were tested on an MX550 resulting in 54fps min and 60fps max @1080p
- `Resolution Scale`: `100%` if TSR or FSR is off
- `View Distance`: `Near`, the map is small so it doesn't matter
- `Anti-Aliasing`: `High`, it's the best balance between quality and performance
- `Post Processing`: `Medium`, High and above enableds DoF which can be taxing
- `Shadows`: `High` Allows soft shadows & volumetric shadows
- `Global Illumination`: `High` (Lumen), it's the best balance between quality and performance
- `Reflections`: `Epic`, Lumen is really performant nowadays
- `Textures`: Low = 1GB, Medium = 2-3GB, High = 4GB, Epic = 6GB
- `Effects`: `High`, it's the best balance between quality and performance
- `Foliage`: `Low`, There's no foliage
- `Shading`: `Epic`, no performance cost until Cinematic

### Made with `Unreal Engine 4.27`, compatible with `Unreal Engine 5.0+`

### Featuring `AMD FSR 2.1`, `Bots` and `Guns!` <a href="https://www.dropbox.com/sh/iaq1bsasgaz5znd/AABZkdeA_N6LC4kTpRVe0Af3a?dl=1">Download here</a>

### Upcoming features

- [X] Update DLSS to DLSS 2.3 or DLSS 3
- [ ] Add FSR 1 for Mac
- [ ] Add graphics options for DLSS or FSR

<img src="img1.png" width="900"/> <hr/>
<img src="tps.png" width="900"/> <hr/>
<img src="img2.png" width="900"/> <hr/>
<img src="Screenshot 2023-07-26 195911.png" width="900"/> <hr/>