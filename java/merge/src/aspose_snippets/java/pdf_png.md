```java

//1. create empty image with calculated width and hight
//use file system as source for save image
fileSource = new com.aspose.imaging.sources.FileCreateSource(
    "Merger_pdf_png.png",
    false);
options = new com.aspose.imaging.imageoptions.PngOptions();
options.setSource(fileSource);
newImage = (com.aspose.imaging.fileformats.png.PngImage) com.aspose.imaging.Image.create(options, newWidth, newHeight);
int stitchedWidth = 0;

//2. read pdf file to Aspose Document
doc = new com.aspose.pdf.Document("1.pdf");

//3. setup default resolution to pdf documents 72dpi
//create image device to save document as image with page dimensions and resolution
//process document page to image
//create bounds to nsert small image into large
for (int pageCount = 1; pageCount <= doc.getPages().size(); pageCount++) {
    resolution = new com.aspose.pdf.devices.Resolution(72);
    imageDevice = new com.aspose.pdf.devices.PngDevice(
                    doc.getPages().get_Item(pageCount).getPageInfo().getWidth(),
                    doc.getPages().get_Item(pageCount).getPageInfo().getHeight(),
                    new com.aspose.pdf.devices.Resolution(72));
    String outPath = "test_" + pageCount + ".png";
    imageDevice.process(doc.getPages().get_Item(pageCount), outPath);

    image = (com.aspose.imaging.RasterImage) com.aspose.imaging.Image.load(outPath);
    bounds = new com.aspose.imaging.Rectangle(
                        stitchedWidth,
                        0,
                        image.getWidth(),
                        image.getHeight());

    //combining images into new one
    newImage.saveArgb32Pixels(bounds,image.loadArgb32Pixels(image.getBounds()));
    stitchedWidth += image.getWidth();
}

//4. save created image to disk
newImage.save();

```