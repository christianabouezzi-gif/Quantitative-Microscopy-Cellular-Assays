# Quantitative-Microscopy-Cellular-Assays
# Cellular Imaging and Quantitative Biomedical Analysis

## Overview

This repository contains a collection of biomedical engineering laboratory projects focused on cellular imaging, microscopy, image processing, spectroscopy, and quantitative biological analysis. Using MATLAB and advanced laboratory instrumentation, biological samples were analyzed through both spatial-domain and frequency-domain techniques to extract meaningful information from cellular systems.

The work combines microscopy, automated image segmentation, Fourier transform analysis, fluorescence measurements, and statistical modeling to investigate biological structures and cellular behavior.

---

## Projects Included

### 1. Blood Smear Image Processing and Cell Quantification

Microscopy images of Wright-stained blood smears were analyzed using MATLAB image-processing techniques to identify and quantify red blood cells (RBCs) and white blood cells (WBCs).

#### Methods

- Color channel separation
- Image thresholding
- Binary segmentation
- Object identification
- Automated cell counting
- Physical scale calibration

#### Results

- Automated RBC quantification
- WBC identification and counting
- Cell density estimation
- Microscopy image characterization

#### Skills Demonstrated

- MATLAB
- Biomedical Image Processing
- Segmentation Algorithms
- Quantitative Microscopy
- Computer Vision

---

### 2. Microscopy Resolution and Contrast Characterization

Microscope performance was evaluated using a USAF 1951 Resolution Target and multiple imaging modalities.

#### Techniques Investigated

- Brightfield Microscopy
- Phase Contrast Microscopy
- Darkfield Microscopy

#### Analysis

- Resolution characterization using the Abbe diffraction limit
- Comparison of contrast enhancement techniques
- Visualization of unstained biological specimens
- Evaluation of optical imaging performance

#### Skills Demonstrated

- Optical Microscopy
- Image Acquisition
- Resolution Analysis
- Experimental Design

---

### 3. Frequency-Domain Analysis of Biological Images

Blood smear images were transformed into the frequency domain using two-dimensional Fast Fourier Transforms (FFT).

#### Methods

- Grayscale conversion
- Mean subtraction
- 2D FFT analysis
- Low-pass filtering
- High-pass filtering
- Image reconstruction

#### Findings

- Low frequencies represented background structure and large-scale image features.
- High frequencies captured cellular boundaries and fine structural details.
- Filtering demonstrated the relationship between spatial frequency content and image sharpness.

#### Skills Demonstrated

- Signal Processing
- Fourier Analysis
- Frequency-Domain Filtering
- MATLAB Programming

---

### 4. SpectraMax i3x Fluorescence-Based Cell Viability Analysis

The SpectraMax i3x Multi-Mode Plate Reader was used to evaluate cellular behavior through fluorescence measurements of cultured fibroblast cells.

#### Experimental Focus

Monitoring fluorescence intensity over time as an indicator of cellular death and viability.

#### Detection Methods

- Fluorescence
- Absorbance
- Luminescence

#### Data Analysis

- Background correction
- Statistical analysis
- ANOVA testing
- Linear regression
- Polynomial regression

#### Results

## Data Analysis

### Statistical Evaluation

A one-way ANOVA was performed to determine whether fluorescence intensity changed significantly throughout the five-day experiment.

**Result**

- p = 0.0002

The analysis demonstrated statistically significant differences in fluorescence measurements across the experimental period, indicating measurable changes in cellular viability.

---

### Linear Regression Analysis

A linear regression model was applied to the average fluorescence values over time.

**Results**

- R² = 0.866
- p = 0.048

The positive slope indicated that fluorescence intensity increased throughout the experiment, suggesting progressive cell death and reduced viability.

---

### Third-Order Polynomial Regression

To investigate potential nonlinear biological behavior, a third-order polynomial regression model was fitted to the fluorescence data.

**Results**

- R² = 0.995

The cubic model captured subtle changes in the rate of fluorescence increase that were not fully represented by the linear model. While the fit closely matched the experimental data, the individual polynomial coefficients were not statistically significant due to the limited number of observations.

The comparison between models suggested that fluorescence progression may not be strictly linear and could involve changing rates of cellular degradation over time.

---

### Model Comparison

| Model | R² | Interpretation |
|---------|---------|---------|
| Linear Regression | 0.866 | Demonstrates a significant overall increase in fluorescence over time |
| 3rd-Order Polynomial Regression | 0.995 | Captures potential nonlinear trends and provides a closer fit to the measured data |

Although the polynomial model produced a higher goodness-of-fit, the linear model provided the more statistically reliable interpretation given the small sample size.
#### Skills Demonstrated

- Fluorescence Spectroscopy
- Plate Reader Operation
- Statistical Analysis
- Experimental Biology
- Data Visualization

---

## Technologies and Equipment

### Software

- MATLAB
- Image Processing Toolbox
- Signal Processing Toolbox

### Laboratory Equipment

- Compound Light Microscope
- CMOS Imaging System
- USAF 1951 Resolution Target
- SpectraMax i3x Multi-Mode Plate Reader

---

## Key Engineering Concepts

- Biomedical Imaging
- Cellular Analysis
- Microscopy
- Image Segmentation
- Fourier Transform Analysis
- Frequency-Domain Filtering
- Fluorescence Spectroscopy
- Quantitative Biology
- Statistical Modeling
- Signal Processing

---

## Repository Structure
