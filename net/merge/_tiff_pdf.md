//1. create empty pdf document
var outputDoc = new Aspose.Pdf.Document();

//2. Load tiff to Aspose image
var multiImage = (Aspose.Imaging.FileFormats.Tiff.TiffImage)Aspose.Imaging.Image.Load("1.tiff");

//3. set active frame to work with
//load bitmap from a frame
//create image savesource to a stream
//create empty image with width and hight
//set frame bounds to save to bitmap
//save frame bitmap to stream
//add new page to document
//create new image into document
//add document image to specific page
foreach (var tiffFrame in multiImage.Frames)
{
    multiImage.ActiveFrame = tiffFrame;
    var pixels = multiImage.LoadPixels(tiffFrame.Bounds);
    var ms = new MemoryStream();
    var createOptions = new Aspose.Imaging.ImageOptions.PdfOptions
    {
        Source = new Aspose.Imaging.Sources.StreamSource(ms)
    };

    var tiffImage = Aspose.Imaging.Image.Create(createOptions, tiffFrame.Width, tiffFrame.Height));
    tiffImage.SavePixels(tiffFrame.Bounds, pixels);
    tiffImage.Save();
    Aspose.Pdf.Page page = outputDoc.Pages.Add();
    var image = new Aspose.Pdf.Image { ImageStream = ms };
    page.Paragraphs.Add(image);
}

//4. save result pdf to file
outputDoc.Save("Merger_tiff_pdf.pdf", Aspose.Pdf.SaveFormat.Pdf);

```