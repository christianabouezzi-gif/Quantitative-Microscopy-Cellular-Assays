# Fluorescence Growth Analysis and Regression Modeling Using MATLAB

## Overview

This project analyzes fluorescence measurements collected from five biological samples over a five-day period. MATLAB was used to perform background correction, statistical analysis, regression modeling, and data visualization to characterize fluorescence growth trends.

The project compares linear and cubic regression models to determine which best represents the observed fluorescence behavior over time.

---

## Objectives

- Analyze fluorescence measurements collected over multiple days
- Correct measurements using background fluorescence values
- Calculate sample averages and variability
- Visualize fluorescence growth trends
- Perform statistical significance testing using ANOVA
- Develop linear and cubic regression models
- Compare predictive performance of regression methods
- Interpret fluorescence behavior over time

---

## Tools Used

- MATLAB
- Statistics and Machine Learning Toolbox

---

## Background Correction

Raw fluorescence measurements were adjusted by subtracting fluorescence contributions from media and background controls.

```matlab
corrected_data = data - background_cells_media;
```

This step ensured that only fluorescence originating from the samples was analyzed.

---

## Fluorescence Growth Curves

<img width="393" height="294" alt="Screenshot 2026-06-16 at 10 01 43 AM" src="https://github.com/user-attachments/assets/804cbf65-cc6c-45b2-adeb-f61d54942bbf" />


Individual sample fluorescence values were plotted over five days to visualize growth trends and sample-to-sample variation.

---

## Average Fluorescence and SEM Analysis

Mean fluorescence values were calculated for each day:

```matlab
means_per_day = mean(corrected_data,1);
```

Standard Error of the Mean (SEM) was computed using:

```matlab
sem_per_day = std_per_day / sqrt(size(corrected_data,1));
```

<img width="389" height="291" alt="Screenshot 2026-06-16 at 10 01 51 AM" src="https://github.com/user-attachments/assets/7b33240d-eb02-4094-87ee-75c204daded5" />


Error bars provide a visual representation of measurement uncertainty across samples.

---

## Statistical Analysis

### One-Way ANOVA

```matlab
[p,tbl,stats] = anova1(fluorescence_values,group_days);
```

### Post-Hoc Comparisons

```matlab
multcompare(stats);
```

These analyses identified statistically significant changes in fluorescence over time.

---

## Linear Regression Analysis

```matlab
mdl_linear = fitlm(days',avg_values');
```

<img width="1399" height="843" alt="linear_reg" src="https://github.com/user-attachments/assets/a66f87f4-15f3-463c-96ab-212a94ef05c8" />


The model estimates the overall rate of fluorescence increase throughout the experiment.

---

## Cubic Regression Analysis

```matlab
p = polyfit(days,avg_values,3);
mdl_poly = fitlm(days',avg_values','poly3');
```

<img width="380" height="282" alt="Screenshot 2026-06-16 at 10 02 14 AM" src="https://github.com/user-attachments/assets/d9fd2f78-e158-4cda-9d52-40a892decb80" />


The cubic model captures nonlinear growth behavior and changes in fluorescence over time.

---

## Model Comparison

<img width="1167" height="875" alt="linear_vs_cubic" src="https://github.com/user-attachments/assets/04c5812a-29af-435d-bb90-3df7586475f3" />


The comparison demonstrates how higher-order polynomial regression can better represent biological growth processes that do not follow a strictly linear trend.

---

## Key MATLAB Functions Used

- mean()
- std()
- errorbar()
- bar()
- anova1()
- multcompare()
- fitlm()
- polyfit()
- polyval()
- scatter()
- plot()

---

## Results Summary

- Successfully corrected fluorescence measurements using background controls
- Quantified variability using SEM error bars
- Identified temporal differences using ANOVA
- Developed linear regression models for trend analysis
- Developed cubic regression models for nonlinear growth analysis
- Compared model performance using visual and statistical methods
- Demonstrated increasing fluorescence over the five-day observation period


---

## Author

### Christian Abou-Ezzi

