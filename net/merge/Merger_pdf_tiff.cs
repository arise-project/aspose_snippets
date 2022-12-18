namespace aspose_snippets.net
{
    public static partial class Merger
    {
        public static void pdf_to_tiff()
        {
            var pathSource1 = @"..\..\TestData\test.pdf";

            //read pdf file to Aspose Document
            var doc = new Aspose.Pdf.Document(pathSource1);

            //make list of Aspose images
            var images = new Aspose.Imaging.Image[doc.Pages.Count];

            //pdf document count pages from 1 to n
            for (int pageCount = 1; pageCount <= doc.Pages.Count; pageCount++)
            {
                //setup default resolution to pdf documents 72dpi
                var resolution = new Aspose.Pdf.Devices.Resolution(72);

                //create image device to save document as image with page dimensions and resolution
                var imageDevice = new Aspose.Pdf.Devices.JpegDevice(
                    (int)doc.Pages[pageCount].PageInfo.Width, 
                    (int)doc.Pages[pageCount].PageInfo.Height, resolution);

                var outPath = "test_"+pageCount+".jpg";

                using var ms = new MemoryStream();
                //process document page to image
                imageDevice.Process(doc.Pages[pageCount], outPath);

                //reset stream to read from begin for next step
                ms.Seek(0, SeekOrigin.Begin);
                
                //load image from file, it supports a lot of formats
                images[pageCount - 1] = Aspose.Imaging.Image.Load(outPath);
            }

            //use file system as source for save image
            Aspose.Imaging.Source fileSource = new Aspose.Imaging.Sources.FileCreateSource(
                "./test.tiff", 
                isTemporal: false); //preserve image on the disk

            using var createOptions = new Aspose.Imaging.ImageOptions.TiffOptions(
                //The default tiff format is no compression with B/W 1 bit per pixel only format. 
                //You can also use this setting to get an empty options and initialize with your tags or other settings.
                Aspose.Imaging.FileFormats.Tiff.Enums.TiffExpectedFormat.Default)
                    {
                        //type of image compression Lzw
                        Compression = Aspose.Imaging.FileFormats.Tiff.Enums.TiffCompressions.Lzw,
                        //Pits per pixel
                        BitsPerSample = new ushort[] { 8, 8, 8 },
                        //Photometric RGB interpolation
                        Photometric = Aspose.Imaging.FileFormats.Tiff.Enums.TiffPhotometrics.Rgb,
                        Source = fileSource
                    };

            using (var tiffImage = Aspose.Imaging.Image.Create(images, true))
            {
                //save tiff file
                tiffImage.Save("test.tiff", createOptions);
            }
        }
    }
}
