
//Load tiff to Aspose image
var multiImage1 = (Aspose.Imaging.FileFormats.Tiff.TiffImage)Aspose.Imaging.Image.Load("1.tiff");

//create empty pdf document
var outputDoc = new Aspose.Pdf.Document();

//set active frame to work with
//load bitmap from a frame
//create image savesource to a stream
//create empty image with width and hight
//set frame bounds to save to bitmap
//save frame bitmap to stream
//add new page to document
foreach (var tiffFrame in multiImage.Frames)
{
    multiImage.ActiveFrame = tiffFrame;
    var pixels = multiImage.LoadPixels(tiffFrame.Bounds);
    var ms = new MemoryStream();
    var createOptions = new Aspose.Imaging.ImageOptions.JpegOptions
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

    //create new image into document
    var image = new Aspose.Pdf.Image
    {
        //set image source to memory stream
        ImageStream = ms
    };

    //add document image to specific page
    page.Paragraphs.Add(image);
}

//save result pdf to file
outputDoc.Save("Merger_tiff_pdf.pdf", Aspose.Pdf.SaveFormat.Pdf);

```