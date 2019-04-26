platform :ios, '8.0'

inhibit_all_warnings!
use_frameworks!

workspace 'NNMacros.xcworkspace'

def all_pods
    pod 'NNMacros', :path => 'NNMacros.podspec'
end

target :NNMacrosDemo do
    project './NNMacrosDemo/NNMacrosDemo'
    all_pods
end
