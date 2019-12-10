//
//  NNMacrosNSNotificationNameExampleSwift.swift
//  NNMacrosExample
//
//  Created by 顾海军 on 2019/12/10.
//  Copyright © 2019 顾海军. All rights reserved.
//

import UIKit

class NNMacrosNSNotificationNameExampleSwift: NSObject, NNMacrosExampleProtocol {
	
	var observer: NSObjectProtocol?
	
	override init() {
		super.init()
		observer = NotificationCenter.default.addObserver(forName: NSNotification.Name.ExampleName0, object: nil, queue: OperationQueue.main, using: { (note) in
			if let object = note.object {
				print(object)
			}
		})
		NotificationCenter.default.addObserver(self, selector: #selector(observerHandler(note:)), name: Notification.Name.ExampleName1, object: nil)
	}
	
	@objc func macroTest() {
		NotificationCenter.default.post(name: NSNotification.Name.ExampleName0, object: "post_name0");
		NotificationCenter.default.post(name: NSNotification.Name.ExampleName1, object: "post_name1");
	}
	
	@objc func observerHandler(note: Notification) {
		if let object = note.object {
			print(object)
		}
	}
	
	deinit {
		if let observer = observer {
			NotificationCenter.default.removeObserver(observer)
		}
	}
}
