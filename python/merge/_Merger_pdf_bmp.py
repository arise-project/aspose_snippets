from Aspose.Imaging.ImageOptions import BmpOptions
from Aspose.Imaging.Sources import FileCreateSource
from Aspose.Imaging import Rectangle
from Aspose.Imaging import Image

from aspose.pdf.devices import BmpDevice
from aspose.pdf.devices import Resolution
from aspose.pdf import Document
import clr

aspose_pdf = clr.addReference("../../lib/Aspose.PDF.dll")
aspose_imaging = clr.addReference("../../lib/Aspose.Imaging.dll")

class pdf_to_bmp(object):
    def __init__(self, licence_path):
        self.dataDir = "../../TestData"
        if licence_path:
            self.licence_path = licence_path
            self.aspose_license = License()
            self.aspose_license.SetLicense(self.licence_path)

    def exec():
        path_source = "../../TestData/test.pdf"

        # read pdf file to Aspose Document
        doc = Document(path_source)

        # make list of path to temporary images
        images = []

        # pages in pdf counted from 1 to n
        for pageCount in range(1, doc.pages.Count):
            # setup default resolution to pdf documents 72dpi
            resolution = Resolution(72)

            # create image device to save document as image with page dimensions and resolution
            image_device = BmpDevice(
                doc.pages[pageCount].PageInfo.width, doc.pages[pageCount].PageInfo.height, resolution)

            out_path = "test_"+pageCount+".bmp"

            # process document page to image
            image_device.Process(doc.pages[pageCount], out_path)
            images.add(out_path)

        # make list pf parsed image sizes
        imageSizes = []
        for path in images:
            # load image from file, it supports a lot of formats
            image = Image.Load(path)
            imageSizes.add(image.Size)

        newWidth = 0
        newHeight = 0
        for s in imageSizes:
            newWidth += s.width
            if newHeight < s.height:
                newHeight = s.height
            else:
                newHeight = newHeight

        # use file system as source for save image
        # preserve image on the disk
        fileSource = FileCreateSource("./test.bmp", False)

        options = BmpOptions
        options.Source = fileSource

        # create empty image with calculated witdh and hight
        newImage = Image.Create(options, newWidth, newHeight)

        stitchedWidth = 0
        for imagePath in images:
            # load image from file, it supports a lot of formats
            image = Image.Load(imagePath)
            # create bounds to insert small image into large
            bounds = Rectangle(stitchedWidth, 0, image.width, image.height)

            # combining images into new one
            # bounds = where to insert image
            # LoadArgb32Pixels = convert image chunk to 32bit Argb
            newImage.saveArgb32Pixels(
                bounds, image.LoadArgb32Pixels(image.Bounds))
            stitchedWidth += image.width

        # save created image to disk
        newImage.save()
