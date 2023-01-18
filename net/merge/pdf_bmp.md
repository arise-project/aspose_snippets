```cs

//use file system as source for save image
//create empty image with calculated witdh and hight
Aspose.Imaging.Source fileSource = new Aspose.Imaging.Sources.FileCreateSource("Merger_pdf_bmp.bmp", false);
options = new Aspose.Imaging.ImageOptions.BmpOptions() { Source = fileSource };
newImage = (Aspose.Imaging.FileFormats.Bmp.BmpImage)Aspose.Imaging.Image.Create(options, newWidth, newHeight));
int stitchedWidth = 0;

//read pdf file to Aspose Document
doc = new Aspose.Pdf.Document("1.pdf");

//combining images into new one
//setup default resolution to pdf documents 72dpi
//create image device to save document as image with page dimensions and resolution
//process document page to image
//create bounds to insert small image into large
for (int pageCount = 1; pageCount <= doc.Pages.Count; pageCount++)
{
    imageDevice = new Aspose.Pdf.Devices.BmpDevice(
        (int)doc.Pages[pageCount].PageInfo.Width,
        (int)doc.Pages[pageCount].PageInfo.Height,
        new Aspose.Pdf.Devices.Resolution(72));

    outPath = "test_"+pageCount+".bmp";

    imageDevice.Process(doc.Pages[pageCount], outPath);
    bounds = new Aspose.Imaging.Rectangle(stitchedWidth,0,image.Width,image.Height);
    newImage.SaveArgb32Pixels(bounds, image.LoadArgb32Pixels(image.Bounds));
    stitchedWidth += image.Width;
}

//save created image to disk
newImage.Save();
```