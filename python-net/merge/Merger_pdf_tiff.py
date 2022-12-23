from Aspose.Imaging import Image
from Aspose.Imaging.FileFormats.Tiff.Enums import TiffPhotometrics
from Aspose.Imaging.FileFormats.Tiff.Enums import TiffCompressions
from Aspose.Imaging.FileFormats.Tiff.Enums import TiffExpectedFormat
from Aspose.Imaging.ImageOptions import TiffOptions
from Aspose.Imaging.Sources import FileCreateSource
from Aspose.Pdf.Devices import JpegDevice
from Aspose.Pdf.Devices import Resolution
from Aspose.Pdf import Document
import clr

aspose_pdf = clr.AddReference("../../lib/Aspose.PDF.dll")
aspose_imaging = clr.AddReference("../../lib/Aspose.Imaging.dll")

class pdf_to_tiff(object):
    def __init__(self, licence_path):
        self.dataDir = "../../TestData"
        if licence_path:
            self.licence_path = licence_path
            self.aspose_license = License()
            self.aspose_license.SetLicense(self.licence_path)

    def exec(self):
        pathSource1 = "../../TestData/test.pdf"

        # read pdf file to Aspose Document
        doc = Document(pathSource1)

        # make list of Aspose images
        images = []

        # pdf document count pages from 1 to n
        for pageCount in range(1, doc.Pages.Length):
            # setup default resolution to pdf documents 72dpi
            resolution = Resolution(72)

            # create image device to save document as image with page dimensions and resolution
            imageDevice = JpegDevice(
                doc.Pages[pageCount].PageInfo.Width, doc.Pages[pageCount].PageInfo.Height, resolution)

            outPath = "test_" + pageCount + ".jpg"

            # process document page to image
            imageDevice.process(doc.Pages[pageCount], outPath)

            # load image from file, it supports a lot of formats
            images[pageCount - 1] = Image.load(outPath)

        # use file system as source for save image
        # preserve image on the disk
        fileSource = FileCreateSource("./test.tiff", False)

        # The default tiff format is no compression with B/W 1 bit per pixel only format.
        # You can also use this setting to get an empty options and initialize with your tags or other settings.
        createOptions = TiffOptions(TiffExpectedFormat.Default)

        # type of image compression Lzw
        createOptions.SetCompression(TiffCompressions.Lzw)
        # Pits per pixel
        createOptions.SetBitsPerSample([8, 8, 8])
        # Photometric RGB interpolation
        createOptions.SetPhotometric(TiffPhotometrics.Rgb)
        createOptions.Source = fileSource

        tiffImage = Image.create(images, True)
        # save tiff file
        tiffImage.Save("test.tiff", createOptions)
