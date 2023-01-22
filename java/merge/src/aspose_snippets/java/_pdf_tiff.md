
//read pdf file to Aspose Document
doc = new com.aspose.pdf.Document("1.pdf");

//setup default resolution to pdf documents 72dpi
//create image device to save document as image with page dimensions and resolution
//process document page to image
for (int pageCount = 1; pageCount <= doc.getPages().size(); pageCount++) {
    com.aspose.pdf.devices.JpegDevice imageDevice = new com.aspose.pdf.devices.JpegDevice(
        (int) doc.getPages().get_Item(pageCount).getPageInfo().getWidth(),
        (int) doc.getPages().get_Item(pageCount).getPageInfo().getHeight(), 
        new com.aspose.pdf.devices.Resolution(72));
    imageDevice.process(doc.getPages().get_Item(pageCount), "test_" + pageCount + ".jpg");
}

//The default tiff format is no compression with B/W 1 bit per pixel only format.
//You can also use this setting to get an empty options and initialize with your tags or other settings.
//use file system as source for save image
com.aspose.imaging.Source fileSource = new com.aspose.imaging.sources.FileCreateSource("test.tiff", false);
com.aspose.imaging.imageoptions.TiffOptions createOptions = new com.aspose.imaging.imageoptions.TiffOptions(com.aspose.imaging.fileformats.tiff.enums.TiffExpectedFormat.Default);
createOptions.setSource(fileSource);

com.aspose.imaging.Image tiffImage = com.aspose.imaging.Image.create(images, true);
//save tiff file
tiffImage.save("Merger_pdf_tiff.tiff", createOptions);
}

```