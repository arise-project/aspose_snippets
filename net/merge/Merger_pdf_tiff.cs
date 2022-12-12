namespace aspose_snippets.net
{
    public static partial class Merger
    {
        public static void pdf_to_tiff()
        {
            var pathSource1 = @"..\..\TestData\test.pdf";

            var doc = new Aspose.Pdf.Document(pathSource1);
            var images = new Aspose.Imaging.Image[doc.Pages.Count];
            for (int pageCount = 1; pageCount <= doc.Pages.Count; pageCount++)
            {
                var resolution = new Aspose.Pdf.Devices.Resolution(72);
                var imageDevice = new Aspose.Pdf.Devices.JpegDevice((int)doc.Pages[pageCount].PageInfo.Width, (int)doc.Pages[pageCount].PageInfo.Height, resolution);
                var outPath = "test_"+pageCount+".jpg";
                using var ms = new System.IO.MemoryStream();
                imageDevice.Process(doc.Pages[pageCount], outPath);
                ms.Seek(0, SeekOrigin.Begin);
                images[pageCount - 1] = Aspose.Imaging.Image.Load(outPath);
            }

            Aspose.Imaging.Source fileSource = new Aspose.Imaging.Sources.FileCreateSource("./test.tiff", isTemporal: false);
            using var createOptions = new Aspose.Imaging.ImageOptions.TiffOptions(Aspose.Imaging.FileFormats.Tiff.Enums.TiffExpectedFormat.Default)
                    {
                        Compression = Aspose.Imaging.FileFormats.Tiff.Enums.TiffCompressions.Lzw,
                        BitsPerSample = new ushort[] { 8, 8, 8 },
                        Photometric = Aspose.Imaging.FileFormats.Tiff.Enums.TiffPhotometrics.Rgb,
                        Source = fileSource
                    };

            using (var tiffImage = Aspose.Imaging.Image.Create(images, true))
            {
                tiffImage.Save("test.tiff", createOptions);
            }
        }
    }
}
