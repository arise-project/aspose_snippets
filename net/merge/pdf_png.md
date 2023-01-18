```cs

//1. use file system as source for save image
//create empty image with calculated width and hight
fileSource = new Aspose.Imaging.Sources.FileCreateSource( "Merger_pdf_png.png", isTemporal: false);
options = new Aspose.Imaging.ImageOptions.PngOptions() { Source = fileSource };
newImage = (Aspose.Imaging.FileFormats.Png.PngImage)Aspose.Imaging.Image.Create(options, newWidth, newHeight);
int stitchedWidth = 0;

//2. read pdf file to Aspose Document
doc = new Aspose.Pdf.Document("1.pdf");

//3. combining images into new one
//setup default resolution to pdf documents 72dpi
//create image device to save document as image with page dimensions and resolution
//process document page to image
//create bounds to nsert small image into large
for (int pageCount = 1; pageCount <= doc.Pages.Count; pageCount++)
{
    imageDevice = new Aspose.Pdf.Devices.PngDevice(
        (int)doc.Pages[pageCount].PageInfo.Width,
        (int)doc.Pages[pageCount].PageInfo.Height,
        new Aspose.Pdf.Devices.Resolution(72));
        outPath = "test_"+pageCount+".png";

    imageDevice.Process(doc.Pages[pageCount], outPath);
    bounds = new Aspose.Imaging.Rectangle(stitchedWidth,0,image.Width,image.Height);
    newImage.SaveArgb32Pixels(bounds, mage.LoadArgb32Pixels(image.Bounds));
    stitchedWidth += image.Width;
}

//4. save created image to disk
newImage.Save();

```