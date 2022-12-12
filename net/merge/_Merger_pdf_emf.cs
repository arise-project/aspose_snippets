namespace aspose_snippets.net
{
    public static partial class Merger
    {
        public static void pdf_to_emf()
        {
            // var pathSource = @"..\..\TestData\test.pdf";

            // var doc = new Aspose.Pdf.Document(pathSource);
            // List<string> images = new List<string>();
            // for (int pageCount = 1; pageCount <= doc.Pages.Count; pageCount++)
            // {
            //     var resolution = new Aspose.Pdf.Devices.Resolution(72);
            //     var imageDevice = new Aspose.Pdf.Devices.EmfDevice((int)doc.Pages[pageCount].PageInfo.Width, (int)doc.Pages[pageCount].PageInfo.Height, resolution);
            //     var outPath = "test_"+pageCount+".emf";
            //     imageDevice.Process(doc.Pages[pageCount], outPath);
            //     images.Add(outPath);
            // }

            // var imageSizes = new List<Aspose.Imaging.Size>();
            // foreach(var path in images)
            // {
            //     using (Aspose.Imaging.RasterImage image = (Aspose.Imaging.RasterImage)Aspose.Imaging.Image.Load(path))
            //     {
            //         imageSizes.Add(image.Size);
            //     }
            // }            

            // int newWidth = imageSizes.Sum(size => size.Width);
            // int newHeight = imageSizes.Max(size => size.Height);

            // // Combining images into new one.
            // Aspose.Imaging.Source fileSource = new Aspose.Imaging.Sources.FileCreateSource("./test.emf", isTemporal: false);
            // var options = new Aspose.Imaging.ImageOptions.EmfOptions() { Source = fileSource };
            // using (var newImage = (Aspose.Imaging.FileFormats.Emf.EmfImage)Aspose.Imaging.Image.Create(options, newWidth, newHeight))
            // {
            //     int stitchedWidth = 0;
            //     foreach (string imagePath in images)
            //     {
                    
            //         using (var image = (Aspose.Imaging.RasterImage)Aspose.Imaging.Image.Load(imagePath))
            //         {
            //             Aspose.Imaging.Rectangle bounds = new Aspose.Imaging.Rectangle(stitchedWidth, 0, image.Width, image.Height);
            //             newImage.Save(image.LoadArgb32Pixels(image.Bounds), bounds);
            //             stitchedWidth += image.Width;
            //         }
            //     }

            //     newImage.Save();
            // }
        }
    }
}
