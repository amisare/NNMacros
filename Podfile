platform :ios, '9.0'

use_frameworks!

workspace 'NNMacros.xcworkspace'

def all_pods
    pod 'NNMacros', :path => 'NNMacros.podspec'
end

target :NNMacrosDemo do
    project './NNMacrosDemo/NNMacrosDemo'
    all_pods
end
