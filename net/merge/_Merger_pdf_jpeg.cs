namespace aspose_snippets.net
{
    public static partial class Merger
    {
        public static void pdf_to_jpeg()
        {
            var pathSource = @"..\..\TestData\test.pdf";

            var doc = new Aspose.Pdf.Document(pathSource);
            List<string> images = new List<string>();
            for (int pageCount = 1; pageCount <= doc.Pages.Count; pageCount++)
            {
                var resolution = new Aspose.Pdf.Devices.Resolution(72);
                var imageDevice = new Aspose.Pdf.Devices.JpegDevice((int)doc.Pages[pageCount].PageInfo.Width, (int)doc.Pages[pageCount].PageInfo.Height, resolution);
                var outPath = "test_"+pageCount+".jpg";
                imageDevice.Process(doc.Pages[pageCount], outPath);
                images.Add(outPath);
            }

            var imageSizes = new List<Aspose.Imaging.Size>();
            foreach(var path in images)
            {
                using (Aspose.Imaging.RasterImage image = (Aspose.Imaging.RasterImage)Aspose.Imaging.Image.Load(path))
                {
                    imageSizes.Add(image.Size);
                }
            }            

            int newWidth = imageSizes.Sum(size => size.Width);
            int newHeight = imageSizes.Max(size => size.Height);

            // Combining images into new one.
            Aspose.Imaging.Source fileSource = new Aspose.Imaging.Sources.FileCreateSource("./test.jpg", isTemporal: false);
            var options = new Aspose.Imaging.ImageOptions.JpegOptions() { Source = fileSource, Quality = 100 };
            using (var newImage = (Aspose.Imaging.FileFormats.Jpeg.JpegImage)Aspose.Imaging.Image.Create(options, newWidth, newHeight))
            {
                int stitchedWidth = 0;
                foreach (string imagePath in images)
                {
                    
                    using (var image = (Aspose.Imaging.RasterImage)Aspose.Imaging.Image.Load(imagePath))
                    {
                        Aspose.Imaging.Rectangle bounds = new Aspose.Imaging.Rectangle(stitchedWidth, 0, image.Width, image.Height);
                        newImage.SaveArgb32Pixels(bounds, image.LoadArgb32Pixels(image.Bounds));
                        stitchedWidth += image.Width;
                    }
                }

                newImage.Save();
            }
        }
    }
}
