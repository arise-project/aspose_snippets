```java

//1. create empty image with calculated width and hight
//use file system as source for save image
//the best quality for jpg
fileSource = new com.aspose.imaging.sources.FileCreateSource("Merger_pdf_jpeg.jpg",false);
options = new com.aspose.imaging.imageoptions.JpegOptions();
options.setSource(fileSource);
options.setQuality(100);
newImage = (com.aspose.imaging.fileformats.jpeg.JpegImage) com.aspose.imaging.Image.create(options, 700, 1000);

//2. read pdf file to Aspose Document
doc = new com.aspose.pdf.Document("1.pdf");
int stitchedWidth = 0;

//3. combining images into new one horisontally
//setup default resolution to pdf documents 72dpi
//create image device to save document as image with page dimensions and resolution
//process document page to image
//create bounds to insert small image into large
for (int pageCount = 1; pageCount <= doc.getPages().size(); pageCount++) {
    imageDevice = new com.aspose.pdf.devices.JpegDevice((int) doc.getPages().get_Item(pageCount).getPageInfo().getWidth(), (int) doc.getPages().get_Item(pageCount).getPageInfo().getHeight(), new com.aspose.pdf.devices.Resolution(72));
    String outPath = "test_" + pageCount + ".jpg";
    imageDevice.process(doc.getPages().get_Item(pageCount), outPath);
    image = (com.aspose.imaging.RasterImage) com.aspose.imaging.Image.load(outPath);
    bounds = new com.aspose.imaging.Rectangle(stitchedWidth,0,image.getWidth(), image.getHeight());
        
    newImage.saveArgb32Pixels(bounds, image.loadArgb32Pixels(image.getBounds()))
    stitchedWidth += image.getWidth();
}

//4. save created image to disk
newImage.save();

```