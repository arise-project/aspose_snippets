from Aspose.Imaging import Rectangle
from Aspose.Imaging.ImageOptions import PngOptions
from Aspose.Imaging.Sources import FileCreateSource
from Aspose.Imaging import Image
from aspose.pdf.Devices import PngDevice
from aspose.pdf.Devices import Resolution
from aspose.pdf import Document
import clr

aspose_pdf = clr.AddReference("../../lib/Aspose.PDF.dll")
aspose_imaging = clr.AddReference("../../lib/Aspose.Imaging.dll")

class pdf_to_png(object):
    def __init__(self, licence_path):
        self.dataDir = "../../TestData"
        if licence_path:
            self.licence_path = licence_path
            self.aspose_license = License()
            self.aspose_license.SetLicense(self.licence_path)

    def exec(self):
        pathSource = "../../TestData/test.pdf"

        # read pdf file to Aspose Document
        doc = Document(pathSource)

        # make list of path to temporary images
        images = []

        # pages in pdf counted from 1 to n
        for pageCount in range(1, doc.Pages.Count):
            # setup default resolution to pdf documents 72dpi
            resolution = Resolution(72)

            # create image device to save document as image with page dimensions and resolution
            imageDevice = PngDevice(
                doc.Pages[pageCount].PageInfo.Width, doc.Pages[pageCount].PageInfo.Height, resolution)

            outPath = "test_"+pageCount+".png"

            # process document page to image
            imageDevice.Process(doc.Pages[pageCount], outPath)
            images.Add(outPath)

        # make list pf parsed image sizes
        imageSizes = []
        for path in images:
            # load image from file, it supports a lot of formats
            image = Image.Load(path)
            imageSizes.Add(image.Size)

        newWidth = 0
        newHeight = 0
        for s in imageSizes:
            newWidth += s.Width
            if newHeight < s.Height:
                newHeight = s.Height
            else:
                newHeight = newHeight

        # use file system as source for save image
        # preserve image on the disk
        fileSource = FileCreateSource("./test.png", False)

        options = PngOptions
        options.Source = fileSource

        # create empty image with calculated width and hight
        newImage = Image.Create(options, newWidth, newHeight)
        stitchedWidth = 0
        for imagePath in images:
            image = Image.Load(imagePath)
            # create bounds to nsert small image into large
            bounds = Rectangle(stitchedWidth, 0, image.Width, image.Height)

            # combining images into new one
            # bounds = where to insert image
            # LoadArgb32Pixels = convert image chunk to 32bit Argb
            newImage.SaveArgb32Pixels(
                bounds, image.LoadArgb32Pixels(image.Bounds))
            stitchedWidth += image.Width

        # save created image to disk
        newImage.Save()
