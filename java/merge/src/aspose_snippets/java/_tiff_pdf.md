
//1. create empty pdf document
com.aspose.pdf.Document outputDoc = new com.aspose.pdf.Document();

//Load tiff to Aspose image
//make list of tiff images to merge
multiImage1 = (com.aspose.imaging.fileformats.tiff.TiffImage) com.aspose.imaging.Image.load("1.tiff");


//iterate through tiff frames
//set active frame to work with
//load bitmap from a frame
//create image savesource to a stream
//create empty image with width and hight
//set frame bounds to save to bitmap
//save frame bitmap to stream
//add new page to document
//create new image into document
//set image source to memory stream
//add document image to specific page
for (com.aspose.imaging.fileformats.tiff.TiffFrame tiffFrame : multiImage.getFrames()) {
    multiImage.setActiveFrame(tiffFrame);

    Color[] pixels = multiImage.loadPixels(tiffFrame.getBounds());
    com.aspose.imaging.Source ms = new com.aspose.imaging.sources.FileCreateSource(
        String.valueOf(index) + "temp.tiff", false);

    com.aspose.imaging.imageoptions.JpegOptions createOptions = new com.aspose.imaging.imageoptions.JpegOptions();
    createOptions.setSource(ms);

    com.aspose.imaging.fileformats.jpeg.JpegImage tiffImage = (com.aspose.imaging.fileformats.jpeg.JpegImage)
    com.aspose.imaging.Image.create(createOptions, tiffFrame.getWidth(), tiffFrame.getHeight());
    tiffImage.savePixels(tiffFrame.getBounds(), pixels);
    tiffImage.save();

    com.aspose.pdf.Page page = outputDoc.getPages().add();
    com.aspose.pdf.Image image = new com.aspose.pdf.Image();
    image.setImageStream(new FileInputStream(String.valueOf(index) + "temp.tiff"));
        page.getParagraphs().add(image);
}

//save result pdf to file
outputDoc.save("Merger_tiff_pdf.pdf", com.aspose.pdf.SaveFormat.Pdf);

```