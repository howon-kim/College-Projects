//
//  ViewController.swift
//  DeAnzaMap
//
//  Created by HWKIM on 2/26/18.
//  Copyright © 2018 Softgine. All rights reserved.
//

import UIKit
import GoogleMaps

class ViewController: UIViewController {

    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view, typically from a nib.
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }
    
    override func loadView() {
        let camera = GMSCameraPosition.camera(withLatitude: 37.320, longitude: -122.045, zoom: 16.0)
        let mapView = GMSMapView.map(withFrame: CGRect.zero, camera: camera)
        
        do {
            // Set the map style by passing the URL of the local file.
            if let styleURL = Bundle.main.url(forResource: "style", withExtension: "json") {
                mapView.mapStyle = try GMSMapStyle(contentsOfFileURL: styleURL)
            } else {
                NSLog("Unable to find style.json")
            }
        } catch {
            NSLog("One or more of the map styles failed to load. \(error)")
        }
        
        let rect = GMSMutablePath()
        rect.add(CLLocationCoordinate2D(latitude: 37.32214, longitude: -122.046983))
        rect.add(CLLocationCoordinate2D(latitude: 37.321234, longitude: -122.046983))
        rect.add(CLLocationCoordinate2D(latitude: 37.321234, longitude: -122.046353))
        rect.add(CLLocationCoordinate2D(latitude: 37.32214,longitude: -122.046353))
        
        // Create the polygon, and assign it to the map.
        let polygon = GMSPolygon(path: rect)
        polygon.fillColor = UIColor(red: 243/255, green: 166/255, blue: 131/255, alpha: 0.3);
        //polygon.strokeColor = .black
        //polygon.strokeWidth = 2
        polygon.title = "hello"
        polygon.map = mapView
        
        self.view = mapView
    }

    // Create a rectangular path


}

