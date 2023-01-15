package aspose_snippets.java;

public class Merger_pdf_tiff {
    public static void Execute() {
        String pathSource1 = "../../TestData/test.pdf";

        //read pdf file to Aspose Document
        com.aspose.pdf.Document doc = new com.aspose.pdf.Document(pathSource1);

        //make list of Aspose images
        com.aspose.imaging.Image [] images = new com.aspose.imaging.Image[doc.getPages().size()];

        //pdf document count pages from 1 to n
        for (int pageCount = 1; pageCount <= doc.getPages().size(); pageCount++) {
            //setup default resolution to pdf documents 72dpi
            com.aspose.pdf.devices.Resolution resolution = new com.aspose.pdf.devices.Resolution(72);

            //create image device to save document as image with page dimensions and resolution
            com.aspose.pdf.devices.JpegDevice imageDevice = new com.aspose.pdf.devices.JpegDevice(
                    (int) doc.getPages().get_Item(pageCount).getPageInfo().getWidth(),
                    (int) doc.getPages().get_Item(pageCount).getPageInfo().getHeight(), resolution);

            String outPath = "test_" + pageCount + ".jpg";

            //process document page to image
            imageDevice.process(doc.getPages().get_Item(pageCount), outPath);

            //load image from file, it supports a lot of formats
            images[pageCount - 1] = com.aspose.imaging.Image.load(outPath);
        }

        //use file system as source for save image
        com.aspose.imaging.Source fileSource = new com.aspose.imaging.sources.FileCreateSource(
                "./test.tiff",
                false); //preserve image on the disk

                com.aspose.imaging.imageoptions.TiffOptions createOptions = new com.aspose.imaging.imageoptions.TiffOptions(
                //The default tiff format is no compression with B/W 1 bit per pixel only format.
                //You can also use this setting to get an empty options and initialize with your tags or other settings.
                com.aspose.imaging.fileformats.tiff.enums.TiffExpectedFormat.Default);

        //type of image compression Lzw
        createOptions.setCompression(com.aspose.imaging.fileformats.tiff.enums.TiffCompressions.Lzw);
        //Pits per pixel
        createOptions.setBitsPerSample(new int[]{8, 8, 8});
        //Photometric RGB interpolation
        createOptions.setPhotometric(com.aspose.imaging.fileformats.tiff.enums.TiffPhotometrics.Rgb);
        createOptions.setSource(fileSource);

        com.aspose.imaging.Image tiffImage = com.aspose.imaging.Image.create(images, true);
        //save tiff file
        tiffImage.save("Merger_pdf_tiff.tiff", createOptions);
    }
}
