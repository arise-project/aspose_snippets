```cs

//1. create empty image with calculated width and hight
//use file system as source for save image
fileSource = new Aspose.Imaging.Sources.FileCreateSource("Merger_pdf_jpeg.jpg",isTemporal: false);
options = new Aspose.Imaging.ImageOptions.JpegOptions() { Source = fileSource, Quality = 100 };
newImage = (Aspose.Imaging.FileFormats.Jpeg.JpegImage)Aspose.Imaging.Image.Create(options, 700, 1000);
int stitchedWidth = 0;

//2. read pdf file to Aspose Document
doc = new Aspose.Pdf.Document("1.pdf");

//3. setup default resolution to pdf documents 72dpi
//create image device to save document as image with page dimensions and resolution
//process document page to image
//create bounds to insert small image into large
//combining images into new one
for (int pageCount = 1; pageCount <= doc.Pages.Count; pageCount++)
{
    imageDevice = new Aspose.Pdf.Devices.JpegDevice((int)doc.Pages[pageCount].PageInfo.Width, (int)doc.Pages[pageCount].PageInfo.Height, new Aspose.Pdf.Devices.Resolution(72));
    outPath = "test_"+pageCount+".jpg";
    imageDevice.Process(doc.Pages[pageCount], outPath);

    bounds = new Aspose.Imaging.Rectangle(stitchedWidth, 0, image.Width, image.Height);
    newImage.SaveArgb32Pixels(bounds,image.LoadArgb32Pixels(image.Bounds));
    stitchedWidth += image.Width;
}

//4. save created image to disk
newImage.Save();
```