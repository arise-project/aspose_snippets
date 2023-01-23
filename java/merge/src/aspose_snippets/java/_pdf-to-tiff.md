//1. Create empty tiff image
com.aspose.imaging.Source fileSource = new com.aspose.imaging.sources.FileCreateSource("test.tiff", false);
com.aspose.imaging.imageoptions.TiffOptions createOptions = new com.aspose.imaging.imageoptions.TiffOptions(com.aspose.imaging.fileformats.tiff.enums.TiffExpectedFormat.Default);
createOptions.setSource(fileSource);
com.aspose.imaging.Image tiffImage = com.aspose.imaging.Image.create("Merger_pdf_to_tiff.tiff", true);

//2. read pdf file to Aspose Document
doc = new com.aspose.pdf.Document("1.pdf");

//4. setup default resolution to pdf documents 72dpi
//create image device to save document as image with page dimensions and resolution
//process document page to image
for (int pageCount = 1; pageCount <= doc.getPages().size(); pageCount++) {
    imageDevice = new com.aspose.pdf.devices.PngDevice(
        (int) doc.getPages().get_Item(pageCount).getPageInfo().getWidth(),
        (int) doc.getPages().get_Item(pageCount).getPageInfo().getHeight(), 
        new com.aspose.pdf.devices.Resolution(72));
    imageDevice.process(doc.getPages().get_Item(pageCount), "test_" + pageCount + ".png");
}

//5. Add the frame to the TIFF image.
// Create a frame based on the PNG image.
frame = new Aspose.Imaging.FileFormats.Tiff.TiffFrame("test_1.png");
tiffImage.AddFrame(frame);

//6. save tiff file
tiffImage.save("Merger_pdf_tiff.tiff", createOptions);

```