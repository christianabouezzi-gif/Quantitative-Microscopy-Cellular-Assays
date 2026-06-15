# Microscopy Image Processing & Blood Cell Quantification 

## Overview
This project focuses on microscopy image processing and quantitative analysis of biological samples using MATLAB. The workflow includes image scaling, grayscale conversion, color channel analysis, segmentation, frequency-domain analysis, and estimation of red and white blood cell density from blood smear images.

Images were analyzed across multiple magnifications (4×, 10×, and 40×) and imaging modalities including brightfield, phase contrast, and darkfield microscopy.

---

## Results Preview

<img width="636" height="508" alt="Screenshot 2026-06-13 at 3 53 11 PM" src="https://github.com/user-attachments/assets/816d7623-5019-41ab-a3d9-846f71279e8c" />



<img width="559" height="420" alt="Screenshot 2025-03-18 at 12 42 44 PM" src="https://github.com/user-attachments/assets/cc8f9d5b-9e44-496e-a51f-bd1875891521" />


<img width="557" height="422" alt="Screenshot 2025-03-18 at 12 42 51 PM" src="https://github.com/user-attachments/assets/f5901eb2-0fba-4b7b-aba6-d24889789c6d" />

<img width="552" height="420" alt="Screenshot 2025-03-18 at 12 44 15 PM" src="https://github.com/user-attachments/assets/fefbc919-961e-419d-a78d-130e060575a2" />



---

## Objectives
- Convert RGB microscopy images to grayscale for processing
- Apply microscope calibration and spatial scaling
- Add calibrated scale bars to microscopy images
- Analyze RGB color channels
- Perform threshold-based segmentation of blood cells
- Estimate red and white blood cell density
- Compare multiple microscopy imaging modalities
- Investigate image structure using Fourier Transform analysis
- Evaluate optical resolution using numerical aperture theory


---

## Tools Used
- MATLAB
- Image Processing Toolbox

---

## Image Processing Workflow

### Image Loading and Grayscale Conversion
Microscopy images were imported using MATLAB and converted from RGB to grayscale using luminance weighting:

I = 0.2989*R + 0.5870*G + 0.1140*B;

This preserves image brightness while simplifying downstream analysis.

---

### Microscope Calibration and Scaling
- Pixel size: 3.6 µm  
- Magnification scaling factor: objective × 0.37  

This is used to convert pixel space into microns.

---

### Scale Bar Visualization

<img width="555" height="419" alt="Screenshot 2025-03-18 at 12 37 11 PM" src="https://github.com/user-attachments/assets/95a6a4d0-ebcd-4884-a27f-9066eaafa107" />


A custom function overlays scale bars and converts pixel coordinates into real-world units.

---

### Cell Imaging Modalities

<img width="555" height="420" alt="Screenshot 2025-03-18 at 12 39 15 PM" src="https://github.com/user-attachments/assets/440743a5-7bae-41ee-9361-994346e1de0b" />


<img width="557" height="422" alt="Screenshot 2025-03-18 at 12 39 08 PM" src="https://github.com/user-attachments/assets/e5b6a5bf-bffe-4bc3-a8b0-975c6f8338aa" />


<img width="554" height="419" alt="Screenshot 2025-03-18 at 12 38 55 PM" src="https://github.com/user-attachments/assets/4d828be5-d32a-4101-a89e-ad247d46ef43" />


Different microscopy modes highlight different cellular structures.

---

### Optical Resolution Theory
Resolution is given by:

d = λ / (2 * NA)

Where:
- λ = 0.5 µm
- NA = 0.10, 0.25, 0.65

This shows the diffraction limit of the microscope system.

---

### RGB Channel Analysis

<img width="557" height="422" alt="Screenshot 2025-03-18 at 12 42 51 PM" src="https://github.com/user-attachments/assets/c16c62f9-9bbe-4f67-9849-fab7156b2b37" />


<img width="552" height="420" alt="Screenshot 2025-03-18 at 12 44 15 PM" src="https://github.com/user-attachments/assets/0de1f789-7f8d-44cb-9d7d-578e81e1af91" />


Channel separation improves contrast for blood cell visualization.

---

### Segmentation and Thresholding

<img width="552" height="420" alt="Screenshot 2025-03-18 at 12 44 15 PM" src="https://github.com/user-attachments/assets/4dc159a7-710e-40d5-b510-b82cb2ed041b" />

<img width="557" height="420" alt="Screenshot 2025-03-18 at 12 44 30 PM" src="https://github.com/user-attachments/assets/ac3910b1-7a72-4d79-9ae6-1618a609b683" />


Binary segmentation is performed using Otsu thresholding (`graythresh`) and intensity filtering.

---

# Frequency Domain Analysis (Fourier Transform)

Fourier Transform analysis was used to investigate the spatial frequency content of microscopy images.

The two-dimensional Fast Fourier Transform (FFT) converts image information from the spatial domain into the frequency domain, revealing repeating structures, image detail, and noise characteristics.

Example MATLAB implementation:
- F = fft2(I);
- F_shift = fftshift(F);
- magnitude_spectrum = log(1 + abs(F_shift));

- imshow(magnitude_spectrum, []);
- title('Fourier Magnitude Spectrum');
  
## Fourier Transform Result

<img width="1182" height="779" alt="Picture1" src="https://github.com/user-attachments/assets/68520130-a89b-492c-88ba-86ce32b4755a" />


Applications include:

- Visualization of spatial frequency content
- Noise characterization
- Resolution analysis
- Identification of repeating structures
- Comparison of image detail across magnifications
---
## Optical Resolution Theory

Microscope resolution was estimated using:
- d = λ / (2 × NA)

Where:

- λ = 0.5 µm
- NA = 0.10, 0.25, 0.65

This relationship defines the diffraction-limited resolving power of the imaging system.
---
## RGB Channel Analysis

Separating color channels improved contrast and enabled more effective identification of blood cell structures.
---
## Segmentation and Thresholding

Segmentation was performed using:

- Otsu thresholding (graythresh)
- Binary image generation (imbinarize)
- Channel-specific intensity filtering

These methods isolated cellular regions for quantitative analysis.

## Blood Smear Quantification

A batch-processing MATLAB workflow analyzed multiple blood smear images to:

- Count RBC pixels
- Count WBC pixels
- Convert pixel counts into area estimates
- Compute averages and standard deviations across samples

This enabled automated estimation of cell density across the dataset.
---
## Key MATLAB Functions Used:

- imread()
- imagesc()
- ginput()
- graythresh()
- imbinarize()
- fft2()
- fftshift()
- abs()
- log()
- sum()
---
## Results Summary
- Converted microscopy images into quantitative biological measurements
- Compared imaging performance across magnifications
- Evaluated brightfield, phase contrast, and darkfield imaging
- Performed Fourier Transform analysis of microscopy images
- Visualized image information in both spatial and frequency domains
- Segmented blood cells using automated thresholding techniques
---
## What I Learned
- Relationship between numerical aperture and optical resolution
- How microscope calibration converts pixels into physical measurements
- Differences between microscopy imaging modalities
- How Fourier Transforms reveal image structure in the frequency domain
- How thresholding can be used for biological image segmentation
- Methods for estimating cell density from microscopy images
---
### Author
Christian Abou-Ezzi

