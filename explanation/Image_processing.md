# Microscopy Image Processing & Blood Cell Quantification (Lab 3)

## Overview
This project focuses on microscopy image processing and quantitative analysis of biological samples using MATLAB. The workflow includes image scaling, grayscale conversion, segmentation, and estimation of red and white blood cell density from blood smear images.

Images are analyzed across multiple magnifications (4×, 10×, 40×) and imaging modalities including brightfield, phase contrast, and darkfield microscopy.

---

## Results Preview

<img width="636" height="508" alt="Screenshot 2026-06-13 at 3 53 11 PM" src="https://github.com/user-attachments/assets/816d7623-5019-41ab-a3d9-846f71279e8c" />



<img width="559" height="420" alt="Screenshot 2025-03-18 at 12 42 44 PM" src="https://github.com/user-attachments/assets/cc8f9d5b-9e44-496e-a51f-bd1875891521" />


<img width="557" height="422" alt="Screenshot 2025-03-18 at 12 42 51 PM" src="https://github.com/user-attachments/assets/f5901eb2-0fba-4b7b-aba6-d24889789c6d" />

<img width="552" height="420" alt="Screenshot 2025-03-18 at 12 44 15 PM" src="https://github.com/user-attachments/assets/fefbc919-961e-419d-a78d-130e060575a2" />



---

## Objectives
- Convert RGB microscopy images to grayscale for processing
- Apply physical scaling using microscope calibration (µm/pixel)
- Add scale bars for spatial interpretation
- Perform RGB channel decomposition
- Apply threshold-based segmentation for RBC/WBC detection
- Estimate cell density from pixel counts
- Compare imaging methods and magnifications
- Evaluate optical resolution using numerical aperture theory

---

## Tools Used
- MATLAB
- Image Processing Toolbox

---

## Image Processing Workflow

### Image Loading and Grayscale Conversion
RGB images are loaded using `imread()` and converted to grayscale using:

I = 0.2989*R + 0.5870*G + 0.1140*B

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

## Blood Smear Quantification
A batch processing loop was used to:
- Count RBC pixels
- Count WBC pixels
- Convert pixels into area estimates
- Compute averages and standard deviation across samples

---

## Key MATLAB Functions Used
- imread()
- imagesc()
- ginput()
- graythresh()
- imbinarize()
- sum()

---

## Results Summary
- Converted microscopy images into quantitative biological data
- Compared resolution across magnifications
- Demonstrated differences between imaging modalities
- Performed automated segmentation of blood cells

---

## What I Learned
- Relationship between numerical aperture and resolution
- How pixel scaling maps to physical measurements
- How imaging modality affects contrast
- How simple segmentation can approximate biological detection

---

## Author

### Christian Abou-Ezzi


