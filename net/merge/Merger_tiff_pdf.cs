namespace aspose_snippets.net
{
    public static partial class Merger
    {
        public static void tiff_to_pdf()
        {
            const string pathSource1 = "../../TestData/test.tiff";
            const string pathSource2 = "../../TestData/Second/test.tiff";

            //Load tiff to Aspose image
            var multiImage1 = (Aspose.Imaging.FileFormats.Tiff.TiffImage)Aspose.Imaging.Image.Load(
                    File.Open(pathSource1, FileMode.Open));
            var multiImage2 = (Aspose.Imaging.FileFormats.Tiff.TiffImage)Aspose.Imaging.Image.Load(
                    File.Open(pathSource2, FileMode.Open));

            //make list of tiff images to merge
            var images = new Aspose.Imaging.FileFormats.Tiff.TiffImage[] {multiImage1, multiImage2};

            //create empty pdf document
            var outputDoc = new Aspose.Pdf.Document();

            foreach (var multiImage in images)
            {
                //iterate through tiff frames
                foreach (var tiffFrame in multiImage.Frames)
                {
                    //set active frame to work with
                    multiImage.ActiveFrame = tiffFrame;

                    //load bitmap from a frame
                    var pixels = multiImage.LoadPixels(tiffFrame.Bounds);

                    var ms = new MemoryStream();

                    //create image savesource to a stream
                    using var createOptions = new Aspose.Imaging.ImageOptions.JpegOptions
                    {
                        Source = new Aspose.Imaging.Sources.StreamSource(ms)
                    };

                    //create empty image with width and hight
                    using (var tiffImage = (Aspose.Imaging.FileFormats.Jpeg.JpegImage)
                        Aspose.Imaging.Image.Create(createOptions, tiffFrame.Width, tiffFrame.Height))
                    {
                        //set frame bounds to save to bitmap
                        tiffImage.SavePixels(tiffFrame.Bounds, pixels);
                        //save frame bitmap to stream
                        tiffImage.Save();
                    }

                    //add new page to document
                    Aspose.Pdf.Page page = outputDoc.Pages.Add();

                    page.PageInfo.Margin.Bottom = 0;
                    page.PageInfo.Margin.Top = 0;
                    page.PageInfo.Margin.Left = 0;
                    page.PageInfo.Margin.Right = 0;
                    page.PageInfo.Width = tiffFrame.Width;
                    page.PageInfo.Height = tiffFrame.Height;

                    //create new image into document
                    var image = new Aspose.Pdf.Image
                    {
                        //set image source to memory stream
                        ImageStream = ms
                    };

                    //add document image to specific page
                    page.Paragraphs.Add(image);
                }
            }

            //save result pdf to file
            outputDoc.Save("Merger_tiff_pdf.pdf", Aspose.Pdf.SaveFormat.Pdf);
        }
    }
}
