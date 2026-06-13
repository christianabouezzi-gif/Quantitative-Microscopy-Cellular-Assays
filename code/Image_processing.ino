close all
clear all

pic_color1=imread('Part2_4xOBJ.bmp');
pic_color2=imread('Part2_10xOBJ.bmp');
pic_color3=imread('Part2_40xOBJ.bmp');

pic1=0.2989*pic_color1(:,:,1)+0.5870*pic_color1(:,:,2)+0.1140*pic_color1(:,:,3);
pic2=0.2989*pic_color2(:,:,1)+0.5870*pic_color2(:,:,2)+0.1140*pic_color2(:,:,3);
pic3=0.2989*pic_color3(:,:,1)+0.5870*pic_color3(:,:,2)+0.1140*pic_color3(:,:,3);

mag4x = 4*0.37;
mag10x = 10*0.37; 
mag40x = 40*0.37;  

pixelSize = 3.6;
barLength = 100;


function ImageWithScaleBar(I,barLength,AdditionalParameterQ3,pixelSize,color)
col1 = color;
micronsPerPixel = pixelSize / AdditionalParameterQ3;
FOV=pixelSize*size(I)/(AdditionalParameterQ3);
%You need to figure out what micronsPerPixel is here
x_range=[0:micronsPerPixel:FOV(2)];
y_range=[0:micronsPerPixel:FOV(1)];
figure
imagesc(x_range, y_range,I);
colormap('gray');
x=[10, 10+barLength];
y=round([y_range(50), y_range(50)]);
line(x,y,'LineWidth',2,'Color',col1);
text(x(1),round(y_range(100)),[num2str(barLength) '\mum'],'FontWeight','bold','FontSize', 15,'Color',col1);
xlabel('microns');
ylabel('microns');
end

ImageWithScaleBar(pic1, 250, mag4x, pixelSize, 'r');
ImageWithScaleBar(pic2, barLength, mag10x, pixelSize, 'r');
ImageWithScaleBar(pic3, 50, mag40x, pixelSize, 'r');

figure(1);
[xpos4x, ypos4x] = ginput(2)
set(gca,'FontSize',12,'fontWeight','bold')
title('USAF 1951 Resolution target 4X')

figure(2);
[xpos10x, ypos10x] = ginput(2)
set(gca,'FontSize',12,'fontWeight','bold')
title('USAF 1951 Resolution target 10X')

figure(3);
[xpos40x, ypos40x] = ginput(2)
set(gca,'FontSize',12,'fontWeight','bold')
title('USAF 1951 Resolution target 40X')

distance_4x = 1000 / sqrt(((diff(xpos4x))^2) + ((diff(ypos4x))^2)) 
distance_10x = 1000 / sqrt((diff(xpos10x))^2 + (diff(ypos10x))^2)
distance_40x = 1000 / sqrt((diff(xpos40x))^2 + (diff(ypos40x))^2)

%%
NA = [.10, .25, .65];
Wavelength = 0.5;
n = 1;

for i = 1:3
    resolution(i) = Wavelength/(2*NA(i));
    theta(i) = asin(NA(i)/n);
    degrees(i) = rad2deg(theta(i));
    min_obs(i) = 1000/(2*resolution(i));
end


%%
pic_color4=imread('Part3.3_10xOBJ.bmp');
pic_color5=imread('Part3.4_10xOBJ.bmp');
pic_color6=imread('Part3.6_10xOBJ.bmp');
pic_color7=imread('Part3.7_10xOBJ.bmp');

pic4=0.2989*pic_color4(:,:,1)+0.5870*pic_color4(:,:,2)+0.1140*pic_color4(:,:,3);
pic5=0.2989*pic_color5(:,:,1)+0.5870*pic_color5(:,:,2)+0.1140*pic_color5(:,:,3);
pic6=0.2989*pic_color6(:,:,1)+0.5870*pic_color6(:,:,2)+0.1140*pic_color6(:,:,3);
pic7=0.2989*pic_color7(:,:,1)+0.5870*pic_color7(:,:,2)+0.1140*pic_color7(:,:,3);

mag4x = 4*0.37;
mag10x = 10*0.37; 
mag40x = 40*0.37;  

pixelSize = 3.6;
barLength = 100;


ImageWithScaleBar(pic4, 50, mag10x, pixelSize, 'r');
set(gca,'FontSize',12,'fontWeight','bold')
title('Brightfield Cheek Cells')
ImageWithScaleBar(pic5, 50, mag10x, pixelSize, 'r');
set(gca,'FontSize',12,'fontWeight','bold')
title('Phase Contrast Cheek Cells')
ImageWithScaleBar(pic6, 50, mag10x, pixelSize, 'r');
set(gca,'FontSize',12,'fontWeight','bold')
title('Phase Contrast Orthogonal Direction Cheek Cells')
ImageWithScaleBar(pic7, 50, mag10x, pixelSize, 'r');
set(gca,'FontSize',12,'fontWeight','bold')
title('Darkfield Cheek Cells')
%%
pic_color8=imread('Part4.3_40xOBJ.bmp');

mag40x = 40*0.37;  
pixelSize = 3.6;
barLength = 100;

red=squeeze(pic_color8(:,:,1));
green=squeeze(pic_color8(:,:,2));
blue=squeeze(pic_color8(:,:,3));

figure('Position',[100,100,800,1000])
subplot(1,3,1);
imshow(red)
title('Red Channel 40X Magnification of RBC')
subplot(1,3,2);
imshow(green)
title('Green Channel 40X Magnification of RBC')
subplot(1,3,3);
imshow(blue)
title('Blue Channel 40X Magnification of RBC')

%%
threshold=graythresh(green);
BW = imcomplement(imbinarize(green, threshold));
rs = (green<185);


ImageWithScaleBar(green, 25, mag40x, pixelSize, 'r');
set(gca,'FontSize',12,'fontWeight','bold')
title('Green Color channel of 40X RBC')


ImageWithScaleBar(BW, 25, mag40x, pixelSize, 'r');
set(gca,'FontSize',12,'fontWeight','bold')
title("Binarized Green channel of 40X RBC")

s=sum(BW(:))
%%

pic_color9=imread('BloodSmear10x_1.bmp');
mag10x = 10*0.37;  
pixelSize = 3.6;
barLength = 100;


red2=squeeze(pic_color9(:,:,1));
green2=squeeze(pic_color9(:,:,2));


ImageWithScaleBar(red2, 25, mag10x, pixelSize, 'r');
set(gca,'FontSize',12,'fontWeight','bold')
title("Red Color Channel of 10X of RBC")
w = (red2<170);
r = (green2<185);
ImageWithScaleBar(w, 25, mag10x, pixelSize, 'r');
set(gca,'FontSize',12,'fontWeight','bold')
title("Binarized Red Color Channel of 10X of RBC")
% ImageWithScaleBar(imcomplement(r), barLength, mag10x, pixelSize, 'r');
% set(gca,'FontSize',12,'fontWeight','bold')
% title("Binarized Red Color Channel of 10X of RBC")
s2=sum(r(:))
s3=sum(w(:))


for n = 1:9
    filename = ['BloodSmear10x_' num2str(n) '.bmp'];
    pic_color11 = imread(filename);
    red5 = squeeze(pic_color11(:,:,1));
    green5 = squeeze(pic_color11(:,:,2));
    w = (red5 < 170); 
    r = (green5 < 185); 
    s2 = sum(r(:)); 
    s3 = sum(w(:)); 
    wbc = s3/7;
    rbc = s2/12;
    RBC_area = rbc/.307
    WBC_area = wbc/.307



    rbc_areas(n) = RBC_area;
    wbc_areas(n) = WBC_area;

    rbc_values(n) = rbc;
    wbc_values(n) = wbc;


    fprintf('Image %d: RBC pixels = %d, WBC pixels = %d\n', n, s2, s3);
    fprintf('Image %d: RBC = %d, WBC = %d\n', n, rbc, wbc);
end

avg_rbc_area = mean(rbc_areas)
std_rbc_area = std(rbc_areas)

avg_wbc_area = mean(wbc_areas)
std_wbc_area = std(wbc_areas)

avg_rbc = mean(rbc_values)
std_rbc = std(rbc_values)

avg_wbc = mean(wbc_values)
std_wbc = std(wbc_values)
%%

green2=squeeze(pic_color9(:,:,2));
ImageWithScaleBar(green2, 25, mag10x, pixelSize, 'r');
set(gca,'FontSize',12,'fontWeight','bold')
title("Green Color Channel of 10X of RBC")
r = (green2 < 185);

ImageWithScaleBar(imcomplement(r), 25, mag10x, pixelSize, 'r');
set(gca,'FontSize',12,'fontWeight','bold')
title("Binarized Green Color Channel of 10X of RBC")
