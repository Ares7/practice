import java.awt.*;
import javax.swing.*;
import java.awt.geom.Line2D;

import java.awt.image.BufferedImage;
import java.io.File;
import java.io.IOException;

import javax.imageio.ImageIO;

import java.io.BufferedReader;
import java.util.Scanner;

public class DrawCirle {

  public static void main(String[] args) {

    // - Radius of the circle in pixel: r
    // - Thickness of the circle in pixel: d
    // - Center of the circle in pixel coordinate: x, y
    // - Size of the image in pixel: h, w

    Scanner in = new Scanner(System.in);

    System.out.println("Please enter Radius of the circle in pixel: ");
    int r = in.nextInt();

    System.out.println("Thickness of the circle in pixel: ");
    int d = in.nextInt();

    System.out.println("Center of the circle in pixel coordinate: x y");
    double x0 = in.nextDouble();
    double y0 = in.nextDouble();

    System.out.println("Size of the image in pixel: h w");
    int h = in.nextInt();
    int w = in.nextInt();

    BufferedImage bImg = new BufferedImage(h, w, BufferedImage.TYPE_BYTE_BINARY);
    Graphics2D g2 = bImg.createGraphics();

    g2.setColor(Color.WHITE);
    g2.fillRect(0, 0, h, w);
    g2.setColor(Color.BLACK);
    g2.setStroke(new BasicStroke(5));

    // draw circle
    double x, y;

    for (int i = 0; i <= 360; i++) {
      x = (x0 + Math.sin(i * (Math.PI / 180)) * r);
      y = (y0 + Math.cos(i * (Math.PI / 180)) * r);

      g2.draw(new Line2D.Double(x0, y0, x, y));

      x0 = x;
      y0 = y;
    }

    try {
      if (ImageIO.write(bImg, "png", new File("./circle.png"))) {
        System.out.println("Image has been generated and saved to the current folder!");
      }
    } catch (IOException e) {
      e.printStackTrace();
    }

  }
}