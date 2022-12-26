from System.IO import FileStream
from System.IO import MemoryStream
from Aspose.Imaging.ImageOptions import JpegOptions
from Aspose.Imaging.Sources import FileCreateSource
from Aspose.Imaging import Image
from aspose.pdf import SaveFormat
from aspose.pdf import PdfImage
from aspose.pdf import Document
import clr

aspose_pdf = clr.addReference("../../lib/Aspose.PDF.dll")
aspose_imaging = clr.addReference("../../lib/Aspose.Imaging.dll")

class tiff_to_pdf(object):
    def __init__(self, licence_path):
        self.dataDir = "../../TestData"
        if licence_path:
            self.licence_path = licence_path
            self.aspose_license = License()
            self.aspose_license.SetLicense(self.licence_path)

    def exec(self):
        path_source1 = "../../TestData/test.tiff"
        path_source2 = "../../TestData/Second/test.tiff"

        # Load tiff to Aspose image
        multiImage1 = Image.Load(path_source1)
        multiImage2 = Image.Load(path_source2)

        # make list of tiff images to merge
        images = [multiImage1, multiImage2]

        # create empty pdf document
        output_doc = Document

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
                    createOptions, tiffFrame.width, tiffFrame.height)
                # set frame bounds to save to bitmap
                tiffImage.savePixels(tiffFrame.Bounds, pixels)
                # save frame bitmap to stream
                tiffImage.save()

                # add new page to document
                page = output_doc.pages.add()

                page.page_info.Margin.Bottom = 0
                page.page_info.Margin.Top = 0
                page.page_info.Margin.Left = 0
                page.page_info.Margin.Right = 0
                page.page_info.width = tiffFrame.width
                page.page_info.height = tiffFrame.height

                # create new image into document
                image = PdfImage
                # set image source to memeory stream
                image.image_stream = FileStream(index.toString() + "temp.tiff")

                # add document image to specific page
                page.Paragraphs.add(image)

        # save result pdf to file
        output_doc.save("test.pdf", SaveFormat.Pdf)
