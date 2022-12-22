from System.IO import FileStream
from System.IO import MemoryStream
from Aspose.Imaging.ImageOptions import JpegOptions
from Aspose.Imaging.Sources import FileCreateSource
from Aspose.Imaging import Image
from Aspose.Pdf import SaveFormat
from Aspose.Pdf import PdfImage
from Aspose.Pdf import Document
import clr

aspose_pdf = clr.AddReference("../../lib/Aspose.PDF.dll")
aspose_imaging = clr.AddReference("../../lib/Aspose.Imaging.dll")


class tiff_to_pdf(object):
    def __init__(self, licence_path):
        self.dataDir = "../../TestData"
        if licence_path:
            self.licence_path = licence_path
            self.aspose_license = License()
            self.aspose_license.SetLicense(self.licence_path)

    def exec(self):

        pathSource1 = "../../TestData/test.tiff"
        pathSource2 = "../../TestData/Second/test.tiff"

        # Load tiff to Aspose image
        multiImage1 = Image.Load(pathSource1)
        multiImage2 = Image.Load(pathSource2)

        # make list of tiff images to merge
        images = [multiImage1, multiImage2]

        # create empty pdf document
        outputDoc = Document()

        index = 1
        for multiImage in images:
            # iterate througn tiff frames
            for tiffFrame in multiImage.Frames:
                # set active frame to work with
                multiImage.ActiveFrame = tiffFrame

                # load bitmap from a frame
                pixels = multiImage.LoadPixels(tiffFrame.Bounds)

                # preserve image on the disk
                ms = FileCreateSource(index + "temp.tiff", False)

                # create image savesource to a stream
                createOptions = JpegOptions
                createOptions.Source = ms

                # create empty image with width and hight
                tiffImage = Image.Create(
                    createOptions, tiffFrame.Width, tiffFrame.Height)
                # set frame bounds to save to bitmap
                tiffImage.SavePixels(tiffFrame.Bounds, pixels)
                # save frame bitmap to stream
                tiffImage.Save()

                # add new page to document
                page = outputDoc.Pages.Add()

                page.PageInfo.Margin.Bottom = 0
                page.PageInfo.Margin.Top = 0
                page.PageInfo.Margin.Left = 0
                page.PageInfo.Margin.Right = 0
                page.PageInfo.Width = tiffFrame.Width
                page.PageInfo.Height = tiffFrame.Height

                # create new image into document
                image = PdfImage
                # set image source to memeory stream
                image.ImageStream = FileStream(index.toString() + "temp.tiff")

                # add document image to specific page
                page.Paragraphs.Add(image)

        # save result pdf to file
        outputDoc.Save("test.pdf", SaveFormat.Pdf)
