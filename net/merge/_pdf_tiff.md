
//use file system as source for save image
//The default tiff format is no compression with B/W 1 bit per pixel only format. 
//You can also use this setting to get an empty options and initialize with your tags or other 
//type of image compression Lzw
//Pits per pixel
//Photometric RGB interpolation
fileSource = new Aspose.Imaging.Sources.FileCreateSource("./test.tiff",isTemporal: false);disk
createOptions = new Aspose.Imaging.ImageOptions.TiffOptions(
                settings.
                Aspose.Imaging.FileFormats.Tiff.Enums.TiffExpectedFormat.Default)
                    {
                        Compression = Aspose.Imaging.FileFormats.Tiff.Enums.TiffCompressions.Lzw,
                        BitsPerSample = new ushort[] { 8, 8, 8 },
                        Photometric = Aspose.Imaging.FileFormats.Tiff.Enums.TiffPhotometrics.Rgb,
                        Source = fileSource
                    };

tiffImage = Aspose.Imaging.Image.Create(images, true);

//read pdf file to Aspose Document
doc = new Aspose.Pdf.Document("1.pdf");

//setup default resolution to pdf documents 72dpi
//create image device to save document as image with page dimensions and resolution
for (int pageCount = 1; pageCount <= doc.Pages.Count; pageCount++)
{
    imageDevice = new Aspose.Pdf.Devices.JpegDevice(
        (int)doc.Pages[pageCount].PageInfo.Width,
        (int)doc.Pages[pageCount].PageInfo.Height, new Aspose.Pdf.Devices.Resolution(72));
    outPath = "test_"+pageCount+".jpg";

    //process document page to image
    imageDevice.Process(doc.Pages[pageCount], outPath);
    
    //load image from file, it supports a lot of formats
    image = Aspose.Imaging.Image.Load(outPath);
}

//save tiff file
tiffImage.Save("Merger_pdf_tiff.tiff", createOptions);