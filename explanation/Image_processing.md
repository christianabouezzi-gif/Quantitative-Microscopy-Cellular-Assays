# Microscopy Image Processing & Blood Cell Quantification (Lab 3)

## Overview
This project focuses on microscopy image processing and quantitative analysis of biological samples using MATLAB. The workflow includes image scaling, grayscale conversion, segmentation, and estimation of red and white blood cell density from blood smear images.

Images are analyzed across multiple magnifications (4×, 10×, 40×) and imaging modalities including brightfield, phase contrast, and darkfield microscopy.

---

## Results Preview

![40x RBC Image](images/rbc_40x.png)

![Binary Segmentation Result](images/rbc_binary.png)

![Microscopy Modalities Comparison](images/microscopy_modes.png)

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

![Scale Bar Example](images/scale_bar.png)

A custom function overlays scale bars and converts pixel coordinates into real-world units.

---

### Cell Imaging Modalities

![Brightfield](images/brightfield.png)
![Phase Contrast](images/phase.png)
![Darkfield](images/darkfield.png)

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

![Red Channel](images/red_channel.png)
![Green Channel](images/green_channel.png)
![Blue Channel](images/blue_channel.png)

Channel separation improves contrast for blood cell visualization.

---

### Segmentation and Thresholding

![Green Channel](images/green_original.png)
![Binary Mask](images/green_binary.png)

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

## File Structure

Lab3-Microscopy-Analysis/
│
├── lab3.m
├── README.md
├── images/
│   ├── rbc_40x.png
│   ├── rbc_binary.png
│   ├── microscopy_modes.png
│   ├── scale_bar.png
│   ├── brightfield.png
│   ├── phase.png
│   ├── darkfield.png
│   ├── red_channel.png
│   ├── green_channel.png
│   ├── blue_channel.png
│   └── green_binary.png
