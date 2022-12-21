namespace aspose_snippets.net
{
    public static partial class Merger
    {
        public static void pdf_to_png()
        {
            var pathSource = "../../TestData/test.pdf";

            //read pdf file to Aspose Document
            var doc = new Aspose.Pdf.Document(pathSource);

            //make list of path to temporary images
            var images = new List<string>();

            //pages in pdf counted from 1 to n
            for (int pageCount = 1; pageCount <= doc.Pages.Count; pageCount++)
            {
                //setup default resolution to pdf documents 72dpi
                var resolution = new Aspose.Pdf.Devices.Resolution(72);

                //create image device to save document as image with page dimensions and resolution
                var imageDevice = new Aspose.Pdf.Devices.PngDevice(
                    (int)doc.Pages[pageCount].PageInfo.Width, 
                    (int)doc.Pages[pageCount].PageInfo.Height, 
                    resolution);

                var outPath = "test_"+pageCount+".png";

                //process document page to image
                imageDevice.Process(doc.Pages[pageCount], outPath);
                images.Add(outPath);
            }

            //make list pf parsed image sizes
            var imageSizes = new List<Aspose.Imaging.Size>();
            foreach(var path in images)
            {
                //load image from file, it supports a lot of formats
                using (Aspose.Imaging.RasterImage image = (Aspose.Imaging.RasterImage)Aspose.Imaging.Image.Load(path))
                {
                    imageSizes.Add(image.Size);
                }
            }            

            int newWidth = imageSizes.Sum(size => size.Width);
            int newHeight = imageSizes.Max(size => size.Height);

            //use file system as source for save image
            Aspose.Imaging.Source fileSource = new Aspose.Imaging.Sources.FileCreateSource(
                "./test.png", 
                isTemporal: false); //preserve image on the disk

            var options = new Aspose.Imaging.ImageOptions.PngOptions() { Source = fileSource };

            //create empty image with calculated width and hight
            using (var newImage = (Aspose.Imaging.FileFormats.Png.PngImage)Aspose.Imaging.Image.Create(options, newWidth, newHeight))
            {
                int stitchedWidth = 0;
                foreach (string imagePath in images)
                {
                    
                    using (var image = (Aspose.Imaging.RasterImage)Aspose.Imaging.Image.Load(imagePath))
                    {
                        //create bounds to nsert small image into large
                        Aspose.Imaging.Rectangle bounds = new Aspose.Imaging.Rectangle(
                            stitchedWidth, 
                            0, 
                            image.Width, 
                            image.Height);
                        
                        //combining images into new one
                        newImage.SaveArgb32Pixels(
                            bounds, //where to insert image
                            image.LoadArgb32Pixels(image.Bounds)); //convert image chunk to 32bit Argb
                        stitchedWidth += image.Width;
                    }
                }

                //save created image to disk
                newImage.Save();
            }
        }
    }
}
