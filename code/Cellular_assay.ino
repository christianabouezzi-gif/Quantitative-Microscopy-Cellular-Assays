samples = {'A','B','C','D','E'};
days = 1:5;

data = [
    249063, 1128084, 1548773, 2138172, 3009017;
    605302, 1787644, 1940160, 3568768, 7157150;
    667703, 1767667, 3135265, 4496502, 11449605;
    496908, 1269086, 2656519, 3460483, 7175332;
    427558, 1397496, 2216634, 1644779, 3405402
];


background_cells_media = [165519, 222734, 276245, 277031, 218776];
background_media = [129819, 175612, 181131, 185307, 160198];

avg_values = [323787.8, 1247261.4, 2023225.2, 2784709.8, 6220525.2];

corrected_data = data - background_cells_media;

means_per_day = mean(corrected_data, 1); 
std_per_day = std(corrected_data, 0, 1); 
sem_per_day = std_per_day / sqrt(size(corrected_data, 1));

figure;
plot(days, data', '-o', 'LineWidth', 1.5);
legend(samples, 'location', 'Best');
xlabel('Day');
ylabel('Fluorescence Value (RFU)');
title('Fluorescence Over 5 Days per Row');
set(gca,'FontSize',12,'fontWeight','bold')
grid on;
saveas(gcf, 'Fluo5Days.png')

figure;
b = bar(days, means_per_day);
hold on

er = errorbar(days, means_per_day, sem_per_day, sem_per_day);
er.Color = 'black';
er.LineStyle = 'none';
er.LineWidth = 1.5;

b.FaceColor = "#EDB120";
b.EdgeColor = "k";

xlabel('Day');
ylabel('Average Fluorescence Value (RFU)');
title('Average Fluorescence per Day with SEM Error Bars');
set(gca, 'FontSize', 12, 'FontWeight', 'bold');
grid on;


for i = 1:length(days)

    y_offset = 0.05 * max(means_per_day);


    if i == length(days)
        y_offset = -0.1 * max(means_per_day);
    end

    text(days(i), means_per_day(i) + sem_per_day(i) + y_offset, ...
        sprintf('%.0f', sem_per_day(i)), ...
        'HorizontalAlignment', 'center', ...
        'FontSize', 10, ...
        'FontWeight', 'bold', ...
        'Color', 'black');
end

hold off
saveas(gcf, 'barGraph_with_SEM_labels.png')



fluorescence_values = corrected_data(:);  
group_days = repmat(days, size(data, 1), 1);  
group_days = group_days(:);  


[p, tbl, stats] = anova1(fluorescence_values, group_days);


multcompare(stats);

%%
sample_A = corrected_data(1, :);
mdl_A = fitlm(days, sample_A);
disp(mdl_A);

for i = 1:size(data, 1)
    mdl = fitlm(days, data(i, :));
    fprintf('Sample %s: Slope = %.2f, p-value = %.4f\n', samples{i}, mdl.Coefficients.Estimate(2), mdl.Coefficients.pValue(2));
end

%%
figure;
scatter(days, avg_values, 80, 'filled', 'r');
xlabel('Day');
ylabel('Average Fluorescence Value (RFU)');
title('Scatter Plot of Averages with Cubic Regression');
set(gca, 'FontSize', 12, 'FontWeight', 'bold');
grid on;
hold on;


p = polyfit(days, avg_values, 3);


x_fit = linspace(min(days), max(days), 100);
y_fit = polyval(p, x_fit);


mdl_poly = fitlm(days', avg_values', 'poly3');
disp(mdl_poly)


plot(x_fit, y_fit, 'r-', 'LineWidth', 2, 'Color', [0.9290 0.6940 0.1250]);


eqn_str = sprintf('y = %.2fx^3 + %.2fx^2 + %.2fx + %.2f', p(1), p(2), p(3), p(4));
text(mean(days)-1.7, mean(avg_values)+3000000, eqn_str, ...
    'FontSize', 12, 'FontWeight', 'bold', 'Color', [0.9290 0.6940 0.1250]);

legend('Average Values', 'Cubic Fit', 'Location', 'Best');

saveas(gcf, 'CubicRegression.png');

%%
X_linear2 = [days', ones(length(days),1)];
mdl_linear2 = fitlm(X_linear2, avg_values');
disp(mdl_linear2);

mdl_linear2 = fitlm(days', avg_values');

slope2 = mdl_linear2.Coefficients.Estimate(2);
intercept2 = mdl_linear2.Coefficients.Estimate(1);


figure;
scatter(days, avg_values, 80, 'filled', 'r');
hold on;


x_fit2 = linspace(min(days), max(days), 100);
y_fit2 = slope2 * x_fit2 + intercept2;
plot(x_fit2, y_fit2, 'b-', 'LineWidth', 2,'Color', [0.9290 0.6940 0.1250]);


xlabel('Day');
ylabel('Average Fluorescence Value (RFU)');
title('Linear Regression of Average Fluorescence Over Days');
set(gca, 'FontSize', 12, 'FontWeight', 'bold');
grid on;


eqn_str = sprintf('y = %.2fx + %.2f', slope2, intercept2);
text(mean(days)-1, mean(avg_values)+1000000, eqn_str, 'FontSize', 12, 'FontWeight', 'bold', 'Color', [0.9290 0.6940 0.1250]);

legend('Data Points', 'Linear Fit', 'Location', 'Best');

saveas(gcf, 'linear_reg.png')
% %%
%linear vs cubic
figure
plot(x_fit2, y_fit2, 'b-', 'LineWidth', 2,'Color', 'r');
hold on
scatter(days, avg_values, 80, 'filled', 'k');
plot(x_fit, y_fit, 'r-', 'LineWidth', 2, 'Color', [0.9290 0.6940 0.1250]);
eqn_str = sprintf('y = %.2fx^3 + %.2fx^2 + %.2fx + %.2f', p(1), p(2), p(3), p(4));
text(mean(days)-1.7, mean(avg_values)+3000000, eqn_str, ...
    'FontSize', 12, 'FontWeight', 'bold', 'Color', [0.9290 0.6940 0.1250]);
eqn_str2 = sprintf('y = %.2fx + %.2f', slope2, intercept2);
text(mean(days), mean(avg_values)-2000000, eqn_str2, 'FontSize', 12, 'FontWeight', 'bold', 'Color', 'r');

legend('Linear Fir', 'Data Points', 'Cubic Fit', 'Location', 'Best');

xlabel('Day');
ylabel('Average Fluorescence Value (RFU)');
title('Linear vs Cubic Regression');
set(gca, 'FontSize', 12, 'FontWeight', 'bold');
grid on;
saveas(gcf, 'linear_cubic_reg.png')
