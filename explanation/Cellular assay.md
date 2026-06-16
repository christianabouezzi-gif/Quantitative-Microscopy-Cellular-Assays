# Fluorescence Growth Analysis and Regression Modeling Using MATLAB

## Overview

This project analyzes fluorescence measurements collected from five biological samples over a five-day period. MATLAB was used to perform background correction, statistical analysis, regression modeling, and data visualization to characterize fluorescence growth trends.

The project compares linear and cubic regression models to determine which best represents the observed fluorescence behavior over time.

---

## Results Preview

### Fluorescence Growth Curves

![Fluorescence Growth Curves](images/Fluo5Days.png)

### Average Fluorescence with SEM Error Bars

![SEM Error Bars](images/barGraph_with_SEM_labels.png)

### Cubic Regression Model

![Cubic Regression](images/CubicRegression.png)

### Linear vs Cubic Regression Comparison

![Linear vs Cubic Regression](images/linear_cubic_reg.png)

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

![Fluorescence Growth Curves](images/Fluo5Days.png)

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

![SEM Error Bars](images/barGraph_with_SEM_labels.png)

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

![Linear Regression](images/linear_reg.png)

The model estimates the overall rate of fluorescence increase throughout the experiment.

---

## Cubic Regression Analysis

```matlab
p = polyfit(days,avg_values,3);
mdl_poly = fitlm(days',avg_values','poly3');
```

![Cubic Regression](images/CubicRegression.png)

The cubic model captures nonlinear growth behavior and changes in fluorescence over time.

---

## Model Comparison

![Linear vs Cubic Regression](images/linear_cubic_reg.png)

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

## What I Learned

- Statistical analysis of biological datasets
- Background correction techniques
- Interpretation of SEM and variability
- Application of ANOVA for significance testing
- Linear regression modeling
- Polynomial regression modeling
- Visualization of biological growth trends
- Model comparison and interpretation

---

## Author

### Christian Abou-Ezzi

Biomedical Engineering Portfolio
