
//1. create empty image with calculated witdh and hight
// use file system as source for save image
com.aspose.imaging.Source fileSource = new com.aspose.imaging.sources.FileCreateSource( "Merger_pdf_bmp.bmp", false);
com.aspose.imaging.imageoptions.BmpOptions options = new com.aspose.imaging.imageoptions.BmpOptions();
options.setSource(fileSource);
com.aspose.imaging.fileformats.bmp.BmpImage newImage = (com.aspose.imaging.fileformats.bmp.BmpImage) com.aspose.imaging.Image.create(options, 700, 1000);

//2. read pdf file to Aspose Document
com.aspose.pdf.Document doc = new com.aspose.pdf.Document("1.pdf");

//3. combining images into new one horisontally
//setup default resolution to pdf documents 72dpi
//create image device to save document as image with page dimensions and resolution
//process document page to image
//load image from file with Aspose Imaging, it supports a lot of formats
//create bounds to insert small image into large
for (int pageCount = 1; pageCount <= doc.getPages().size(); pageCount++) {
    com.aspose.pdf.devices.BmpDevice imageDevice = new com.aspose.pdf.devices.BmpDevice(
        doc.getPages().get_Item(pageCount).getPageInfo().getWidth(),
        doc.getPages().get_Item(pageCount).getPageInfo().getHeight(),
        new com.aspose.pdf.devices.Resolution(72));
        String outPath = "test_" + pageCount + ".bmp";
        imageDevice.process(doc.getPages().get_Item(pageCount), outPath);

        com.aspose.imaging.RasterImage image = (com.aspose.imaging.RasterImage) com.aspose.imaging.Image.load(outPath);
        com.aspose.imaging.Rectangle bounds = new com.aspose.imaging.Rectangle(
                    stitchedWidth,
                    0,
                    image.getWidth(),
                    image.getHeight());
        newImage.saveArgb32Pixels(
                    //where to insert image
                    bounds,
                    //convert image chunk to 32bit Argb
                    image.loadArgb32Pixels(image.getBounds()));
            stitchedWidth += image.getWidth();
        
}

//4. save created image to disk
newImage.save();