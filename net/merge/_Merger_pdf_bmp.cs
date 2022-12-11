namespace aspose_snippets.net
{
    public static partial class Merger
    {
        public static void pdf_to_bmp()
        {
            // var pathSource = @"..\..\TestData\test.pdf";

            // var doc = new Aspose.Pdf.Document(pathSource);
            // List<string> images = new List<string>();
            // for (int pageCount = 1; pageCount <= doc.Pages.Count; pageCount++)
            // {
            //     var resolution = new Aspose.Pdf.Devices.Resolution(72);
            //     var imageDevice = new Aspose.Pdf.Devices.JpegDevice(doc.Pages[pageCount].PageInfo.Width, doc.Pages[pageCount].PageInfo.Height, resolution);
            //     var outPath = "test_"+pageCount+".bmp";
            //     imageDevice.Process(doc.Pages[pageCount], outPath);
            //     images.Add(outPath);
            // }

            // var imageSizes = new List<Aspose.Imaging.Size>();
            // foreach(var path in images)
            // {
            //     using (Aspose.Imaging.RasterImage image = (Aspose.Imaging.RasterImage)Aspose.Imaging.Image.Load(imagePath))
            //     {
            //         imageSizes.Add(image.Size);
            //     }
            // }            

            // int newWidth = imageSizes.Sum(size => size.Width);
            // int newHeight = imageSizes.Max(size => size.Height);

            // // Combining images into new one.
            // Aspose.Imaging.Source tempFileSource = new Aspose.Imaging.FileCreateSource("test.bmp");
            // var options = new Aspose.Imaging.BmpOptions() { Source = "test.bmp", Quality = 100 };
            // using (Aspose.Imaging.BmpImage newImage = (Aspose.Imaging.BmpImage)Aspose.Imaging.Image.Create(options, newWidth, newHeight))
            // {
            //     int stitchedWidth = 0;
            //     foreach (string imagePath in images)
            //     {
            //         using (var image = (Aspose.Imaging.RasterImage)Image.Load(imagePath))
            //         {
            //             Aspose.Imaging.Rectangle bounds = new Aspose.Imaging.Rectangle(stitchedWidth, 0, image.Width, image.Height);
            //             newImage.SaveArgb32Pixels(bounds, image.LoadArgb32Pixels(image.Bounds));
            //             stitchedWidth += image.Width;
            //         }
            //     }

            //     newImage.Save("test.bmp");
            // }
        }
    }
}
