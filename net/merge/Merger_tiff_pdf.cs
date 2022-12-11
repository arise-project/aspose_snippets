namespace aspose_snippets.net
{
    public static partial class Merger
    {
        public static void tiff_to_pdf()
        {
            var pathSource1 = @"..\..\TestData\test.tiff";
            var pathSource2 = @"..\..\TestData\Second\test.tiff";
            
            var multiImage1 = (Aspose.Imaging.FileFormats.Tiff.TiffImage)Aspose.Imaging.Image.Load(File.Open(pathSource1, FileMode.Open));
            var multiImage2 = (Aspose.Imaging.FileFormats.Tiff.TiffImage)Aspose.Imaging.Image.Load(File.Open(pathSource2, FileMode.Open));

            var images = new Aspose.Imaging.FileFormats.Tiff.TiffImage[] {multiImage1, multiImage2};

            var outputDoc = new Aspose.Pdf.Document();
            foreach (var multiImage in images)
            {
                foreach (var tiffFrame in multiImage.Frames)
                {
                    multiImage.ActiveFrame = tiffFrame;
                    var pixels = multiImage.LoadPixels(tiffFrame.Bounds);

                    MemoryStream ms = new MemoryStream();
                    using var createOptions = new Aspose.Imaging.ImageOptions.JpegOptions
                    {
                        Source = new Aspose.Imaging.Sources.StreamSource(ms)
                    };

                    using (var tiffImage = (Aspose.Imaging.FileFormats.Jpeg.JpegImage)
                        Aspose.Imaging.Image.Create(createOptions, tiffFrame.Width, tiffFrame.Height))
                    {
                        tiffImage.SavePixels(tiffFrame.Bounds, pixels);
                        tiffImage.Save();
                    }

                    Aspose.Pdf.Page page = outputDoc.Pages.Add();
                    page.PageInfo.Margin.Bottom = 0;
                    page.PageInfo.Margin.Top = 0;
                    page.PageInfo.Margin.Left = 0;
                    page.PageInfo.Margin.Right = 0;
                    page.PageInfo.Width = tiffFrame.Width;
                    page.PageInfo.Height = tiffFrame.Height;
                    var image = new Aspose.Pdf.Image();
                    image.ImageStream = ms;
                    page.Paragraphs.Add(image);
                }
            }
            outputDoc.Save("test.pdf", Aspose.Pdf.SaveFormat.Pdf);
        }
    }
}
